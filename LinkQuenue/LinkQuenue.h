#ifndef _LINKQUENUE_H
#define _LINKQUENUE_H

typedef void LinkQuenue;

LinkQuenue *LinkQuenue_create();
void LinkQuenue_destory(LinkQuenue *quenue);
void LinkQuenue_clear(LinkQuenue *quenue);
int LinkQuenue_append(LinkQuenur *quenue, void *item);
void *LinkQuenue_retrieve(LinkQuenue *quenue);
void *LinkQuenue_header(LinkQuenue *quenue);
int LinkQuenue_length(LinkQuenue *quenue);








#endif
