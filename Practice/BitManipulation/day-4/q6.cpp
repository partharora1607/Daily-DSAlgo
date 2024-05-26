// time complexity : o(1)

int OnesComplement(int n) { return n ^ (2 * ((1 << int(log2(n))) - 1) | 1); }
