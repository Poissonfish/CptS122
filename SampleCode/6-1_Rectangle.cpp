#include "6-1_Rectangle.h"

Rectangle::Rectangle()
{
	mLength = 0.0;
	mWidth = 0.0;
	std::cout << "inside constructor for Rectangle" << std::endl;

}

Rectangle::Rectangle(Rectangle &copy)
{
	// defining the way to copy Rectangle objects!
	mLength = copy.getLength();
	mWidth = copy.getWidth();
}

Rectangle::~Rectangle()
{
	std::cout << "inside destructor for Rectangle" << std::endl;
}

// constantt object can only invoke constant functions
Rectangle & Rectangle::operator= (const Rectangle &rhs)
{
	mLength = rhs.getLength();
	mWidth = rhs.getWidth();

	return (*this);
}

double Rectangle::getLength() const
{
	return mLength;
}

double Rectangle::getWidth() const
{
	return mWidth;
}

void Rectangle::setLength(double newLength)
{
	mLength = newLength;
}

void Rectangle::setWidth(double newWidth)
{
	if (newWidth > 0.0) // we can validate that width is > 0
	{
		mWidth = newWidth;
	}
	else
	{
		mWidth = 0.0;
	}
}

double Rectangle::computeArea()
{
	return mLength * mWidth;
}

// non member
ostream & operator<< (ostream &lhs, Rectangle &rhs)
{
	lhs << "width: " << rhs.getWidth() << ", " << "length: " << rhs.getLength();

	return lhs;
}
