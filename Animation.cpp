#include "Animation.h"

short Animation::Animate()
{
    if (!End)
    {
        if (Half_done)
        {
            Progression += 1;
            if (Progression > 10)
            {
                Progression = 10;
                End = true;
            }
        }
        else
        {
            Progression -= 1;
            if (Progression < 0)
            {
                Progression = 0;
                Half_done = true;
            }
        }
    }

    return Progression;
}

void Animation::Start()
{
    End = false;
    Half_done = false;
}
