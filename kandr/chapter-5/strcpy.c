/* strcpy: copy t to s; array subscript version */
void strcpy(char *s, char *t){ 
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0'){
        i++;
    }
}
/* pointer version*/
void strcpy(char *s, char *t){
    while ((*s = *t) != '\0'){
        *s++;
        *t++;
    }
}
/*compact version*/
void strcpy(char *s, char *t){
    while ((*s++ = *t++) != '\0')
        ;
}
/*even more compact*/
void strcpy(char *s, char *t){
    while (*s++ = *t++)
        ;
}