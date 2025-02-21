#ifndef ORDER_HPP
#define ORDER_HPP

#include <chrono>

enum class OrderType { LIMIT, MARKET };
enum class Side { BUY, SELL };

struct Order {
    int orderId;
    Side side;
    double price;
    int quantity;
    OrderType type;
    std::chrono::time_point<std::chrono::high_resolution_clock> timestamp;

    Order(int id, Side s, double p, int q, OrderType t)
        : orderId(id), side(s), price(p), quantity(q), type(t), timestamp(std::chrono::high_resolution_clock::now()) {}
};

#endif /* ORDER_HPP */