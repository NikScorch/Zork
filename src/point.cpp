
#include "include/point.h"

Point::Point() 
    : x(0), y(0)
{

}

Point::Point(int x, int y) 
    : x(x), y(y)
{

}

Point::Point(const Point& other) {
    this->x = other.getX();
    this->y = other.getY();   
}

int Point::getX() const
{
    return this->x;
}

int Point::getY() const
{
    return this->y;
}

void Point::setX(int x)
{
    this->x = x;
}

void Point::setY(int y)
{
    this->y = y;
}

Point Point::operator+(const Point other) const
{
    return Point(this->getX() + other.getX(), this->getY() + other.getY());
}

Point Point::operator-(const Point other) const
{
    return Point(this->getX() - other.getX(), this->getY() - other.getY());
}

bool Point::operator<(const Point other) const
{
    return this->getX() < other.getX() && this->getY() < other.getY();
}

bool Point::operator>(const Point other) const
{
    return this->getX() > other.getX() && this->getY() > other.getY();
}
