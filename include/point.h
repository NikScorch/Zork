#ifndef POINT_H
#define POINT_H

class Point 
{
public:
    Point();
    Point(int x, int y);
    Point(const Point& other);

    int getX() const;
    int getY() const;

    void setX(int x);
    void setY(int y);

    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;
    bool operator<(const Point& other) const;
    bool operator>(const Point& other) const;

    friend class Entity;
private:
    int x, y;
};

#endif  // point_h
