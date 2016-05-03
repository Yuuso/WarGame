
#include "Position.h"


__vec2::__vec2() : x(0.0f), y(0.0f)
{
}
__vec2::__vec2(const float& _xy) : x(_xy), y(_xy)
{
}
__vec2::__vec2(const float& _x, const float& _y) : x(_x), y(_y)
{
}
__vec2::__vec2(const yam2d::vec2& _yamvec) : x(_yamvec.x), y(_yamvec.y)
{	
}

yam2d::vec2 __vec2::operator=(const yam2d::vec2& _other)
{
	return yam2d::vec2(this->x, this->y);
}

bool __vec2::operator==(const __vec2& _other) const
{
	if (this->x == _other.x && this->y == _other.y)
		return true;
	return false;
}
bool __vec2::operator!=(const __vec2& _other) const
{
	if (this->x == _other.x && this->y == _other.y)
		return false;
	return true;
}


bool __vec2::operator<(const __vec2& _other) const
{
	return this->length() < _other.length();
}
bool __vec2::operator>(const __vec2& _other) const
{
	return this->length() > _other.length();
}


__vec2 operator+(const __vec2& _v1, const __vec2& _v2)
{
	return __vec2(_v1.x + _v2.x, _v1.y + _v2.y);
}
__vec2 operator-(const __vec2& _v1, const __vec2& _v2)
{
	return __vec2(_v1.x - _v2.x, _v1.y - _v2.y);
}

slm::vec2 __vec2::asslmvec() const 
{
	return slm::vec2(this->x, this->y);
}
const slm::vec2 __vec2::asconstslmvec() const
{

	const slm::vec2 value(this->x, this->y);
	return value;
}


float __vec2::length() const
{
	return sqrt(x*x + y*y);
}