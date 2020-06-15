int read_in(int socket, char *buf, int len);
void bind_to_port(int socket, int sin_port);
int open_listener_socket();
int say(int socket, char *s);
void error(char *msg);
int listener_d;
void handle_shutdown(int sig);
int catch_signal(int sig, void (*handle_shutdown)(int));

