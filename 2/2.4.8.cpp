int strstr(const char *text, const char *pattern)
{
    for(int i = 0; *text != '\0' || *pattern == '\0'; i++, text++)
        for(int j = 0; *(text + j) == *(pattern + j) || *pattern == '\0'; j++)
            if(*(pattern + j + 1) == '\0' || *pattern == '\0')
                return i;
    return -1; 
}