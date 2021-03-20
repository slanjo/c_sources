/* strcmpr return <0 if s < t, 0 ir s == t, >0 if s > t */
/*int strcmp(char *s, char *t){
    int i;

    for (i = 0; s[i] == t[i], i++){
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
    }
}*/
/* strcmpr return <0 if s < t, 0 ir s == t, >0 if s > t POINTER VERSION */
int strcmp(char *s, char *t){
    int i;
    for ( ; *s++ == *t++, ){
        if (*s == '\0'){
            return 0
        }
    }

}