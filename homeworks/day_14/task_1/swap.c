void swap(int *lhs, int *rhs)
{
    *lhs ^= *rhs;
    *rhs ^= *lhs;
    *lhs ^= *rhs;
}