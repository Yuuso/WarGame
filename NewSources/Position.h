
#pragma once

#include <vec2.h>


struct __vec2
{
	__vec2();
	__vec2(const float& _xy);
	__vec2(const float& _x, const float& _y);
	__vec2(const yam2d::vec2& _yamvec);

	yam2d::vec2 operator=(const yam2d::vec2& _other);

	bool operator==(const __vec2& _other) const;
	bool operator!=(const __vec2& _other) const;

	bool operator<(const __vec2& _other) const;
	bool operator>(const __vec2& _other) const;

	friend __vec2 operator+(const __vec2& _v1, const __vec2& _v2);
	friend __vec2 operator-(const __vec2& _v1, const __vec2& _v2);

	slm::vec2 asslmvec() const;
	const slm::vec2 asconstslmvec() const;

	float length() const;

	float x, y;
};