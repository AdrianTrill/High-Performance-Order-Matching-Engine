#include "order_book.hpp"
#include <iostream>

OrderBook::OrderBook()
    : buyOrders([](const Order& a, const Order& b) { return a.price < b.price; }),
      sellOrders([](const Order& a, const Order& b) { return a.price > b.price; }) {}

void OrderBook::addOrder(const Order& order) {
    std::lock_guard<std::mutex> lock(bookMutex);
    orderMap[order.orderId] = order;

    if (order.side == Side::BUY) {
        buyOrders.push(order);
    } else {
        sellOrders.push(order);
    }
    matchOrders();
}

void OrderBook::matchOrders() {
    while (!buyOrders.empty() && !sellOrders.empty()) {
        Order buyOrder = buyOrders.top();
        Order sellOrder = sellOrders.top();

        if (buyOrder.price < sellOrder.price) {
            break;
        }

        int tradeQty = std::min(buyOrder.quantity, sellOrder.quantity);
        buyOrders.pop();
        sellOrders.pop();

        std::cout << "Matched Order: " << tradeQty << " shares at price " << sellOrder.price << "\n";

        if (buyOrder.quantity > tradeQty) {
            buyOrder.quantity -= tradeQty;
            buyOrders.push(buyOrder);
        }
        if (sellOrder.quantity > tradeQty) {
            sellOrder.quantity -= tradeQty;
            sellOrders.push(sellOrder);
        }
    }
}

void OrderBook::cancelOrder(int orderId) {
    std::lock_guard<std::mutex> lock(bookMutex);
    orderMap.erase(orderId);
}