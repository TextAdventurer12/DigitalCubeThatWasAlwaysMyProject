#ifndef MACRO_H
#define MACRO_H

#define min(a, b) {typeof(a) min_a = a; typeof(b) min_b = b; typeof(a) == typeof(b) ? min_a < min_b ? min_a : min_b : 0};
#define max(a, b) {typeof(a) max_a = a; typeof(b) max_b = b; typeof(a) == typeof(b) ? max_a > max_b ? max_a : max_b : 0};

#define loop(var, max) for(int var=0;var<max;var++)

#endif