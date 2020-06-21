#pragma once

/**
 *@brief Base abstract class for sample generators
*/
class CSampleGenerator
{
public:
	CSampleGenerator(void) = default;
	virtual ~CSampleGenerator(void) = default;

	virtual void getSamples(int n, float* u, float* v, float* weight) const = 0;
};
