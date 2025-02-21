#include "order_book.hpp"
#include <thread>
#include <chrono>
#include <cstdlib>

void orderGenerator(OrderBook &book) {
    int orderId = 1;
    while (true) {
        Side side = (rand() % 2) ? Side::BUY : Side::SELL;
        double price = 100.0 + (rand() % 100) / 10.0;
        int quantity = (rand() % 50) + 1;
        Order order(orderId++, side, price, quantity, OrderType::LIMIT);
        book.addOrder(order);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main() {
    OrderBook book;
    std::thread t1(orderGenerator, std::ref(book));
    t1.join();
    return 0;
}