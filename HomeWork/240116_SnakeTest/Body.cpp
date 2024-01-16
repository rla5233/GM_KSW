#include "Body.h"

void Body::Update()
{
	if (Front == nullptr)
	{
		return;
	}

	SetPos(Front->GetPos());
}
