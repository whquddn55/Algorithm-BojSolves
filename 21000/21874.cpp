#include "hat.h"
using I=int;void init(I N){}I call(vector<I>F,vector<I>B,I n){I a{};for(I e:F)a^=e;for(I e:B)a^=e;return a;}