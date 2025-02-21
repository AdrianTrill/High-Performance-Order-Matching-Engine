#ifndef ORDER_BOOK_HPP
#define ORDER_BOOK_HPP

#include "order.hpp"
#include <queue>
#include <unordered_map>
#include <mutex>

class OrderBook {
private:
    std::priority_queue<Order, std::vector<Order>, std::function<bool(const Order&, const Order&)>> buyOrders;
    std::priority_queue<Order, std::vector<Order>, std::function<bool(const Order&, const Order&)>> sellOrders;
    std::unordered_map<int, Order> orderMap;
    std::mutex bookMutex;

public:
    OrderBook();
    void addOrder(const Order& order);
    void matchOrders();
    void cancelOrder(int orderId);
};

#endif /* ORDER_BOOK_HPP */