#include "stdio.h"
#include "math.h"
#include "string.h"
#include "algebra.h"

void vec2_copy(const vec2_t v, vec2_t rt) {
	memcpy(rt, v, sizeof(float)*2);
}

void vec2_show(const vec2_t v) {
	printf("%5.2f %5.2f\n", v[_XC], v[_YC]);
}

void vec2_zero(vec2_t v) {
	v[0] = 0.0f;
	v[1] = 0.0f;
}

void vec2_set(float x, float y, vec3_t rt) {
	rt[0] = x;
	rt[1] = y;
}

float vec2_lenght(const vec2_t v) {
	return sqrtf(v[_XC]*v[_XC] +
				 v[_YC]*v[_YC]);

}

void vec3_normalize_self(vec3_t v) {
	float len;
	
	len = vec3_lenght(v);

	if (len > f_eps) {
		v[_ZC] = v[_ZC] / len;
		v[_XC] = v[_XC] / len;
		v[_YC] = v[_YC] / len;
	} else {
		printf("vec3_normalize_self(): vector is too short!");
		return;
	}
}

void vec3_get_normalize(const vec3_t v, vec3_t rt) {
	vec3_copy(v, rt);

	vec3_normalize_self(rt);
}

void vec3_scale(const vec3_t v, const float scale, vec3_t rt) {
	rt[0] *= scale;
	rt[1] *= scale;
	rt[2] *= scale;
}

void vec3_invert_self(vec3_t v) {
	v[_XC] = -v[_XC];
	v[_YC] = -v[_YC];
	v[_ZC] = -v[_ZC];
}

void vec3_get_invert(const vec3_t v, vec3_t rt) {
	vec3_copy(v, rt);

	vec3_invert_self(rt);
}

float vec3_dot(const vec3_t a, const vec3_t b) {
	return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

void vec3_sum(const vec3_t a, const vec3_t b, vec3_t rt) {
	rt[0] = a[0] + b[0];
	rt[1] = a[1] + b[1];
	rt[2] = a[2] + b[2];
}

void vec3_sub(const vec3_t a, const vec3_t b, vec3_t rt) {
	rt[0] = a[0] - b[0];
	rt[1] = a[1] - b[1];
	rt[2] = a[2] - b[2];
}

void vec3_cross(const vec3_t a, const vec3_t b, vec3_t rt) {
	rt[0] = a[_YC]*b[_ZC] - a[_ZC]*b[_YC];
	rt[1] = a[_ZC]*b[_XC] - a[_XC]*b[_ZC];
	rt[2] = a[_XC]*b[_YC] - a[_YC]*b[_XC];
}