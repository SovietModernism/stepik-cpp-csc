void strcat(char *to, const char *from)
{
    while(*to != 0) ++to;
    do {
        *to = *from;
    } while(++to, *from++ != 0);
}