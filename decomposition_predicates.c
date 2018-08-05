#include "inner.h"

int
	has_nanf(
		t_s_dfp *dec)
{
	if (dec->flags & NAN_F)
		return (1);
	return (0);
}
