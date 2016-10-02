#include <stdio.h>
#include <stdlib.h>
#include "LinkQuenue.h"

typedef struct _tag_LinkQuenue
{
    struct _tag_LinkQuenue *next;
    void *item;
}TLinkQuenue;

typedef struct _tag_LinkQuenueNode
{
    TLinkQuenueNode *front;
    TLinkQuenueNode *rear;
    int length;
}TLinkQuenue;

LinkQuenue *LinkQuenue_create()
{
    TLinkQuenue *ret = (TLinkQuene *)malloc(sizeof(TLinkQuenue));
    if( ret )
    {
    	ret->front = NULL;
	ret->rear = NULL;
	ret->length = 0;
    }
    return ret ;
}

void LinkQuenue_destory(LinkQuenue *qenue)
{
    LinkQuene_clear(quenue);
    free(quenue);
}

void LinkQuenue_clear(LinkQuenue *quenue)
{
     while(LinkQuenue_length(quenue) > 0)
     {
     	LinkQuenue_retrieve(quenue);
     }
}

int LinkQuenue_append(LinkQuenue *quenue, void *item)
{
     TLinkQuenue *Quenue = (TLinkQuenue *)quenue;
     TLinkQuenueNode *node = (TLinkQuenueNode *)malloc(sizeof(TLinkQuenueNode));
     int ret = (Quenue != NULL )&&(item != NULL);
     if( ret )
     {
     	node->item = item;
     	if(Quenue->length > 0)
	{
	    Quenue->rear.next = node;
	    Quenue->rear = node;
	    node->next = NULL;
	}
	else 
	{
	    Quenue->front = node;
	    Quenue->rear = node;
	    node->next = NULL;
	}
	Quenue->length++;
     }
     else
     {
         free(node);
     }
     return ret ;
     
}

void *LinkQuenue_retrieve(LinkQuenue *quenue)
{
    TLinkQuenue *Quenue = (TLinkQuenue *)quenue;
    TLinkQuenueNode *node = NULL;
    void *ret = NULL;
    if( Quenue )
    {
    	node = Quenue->front;
	Quenue->front = node->next;
	ret = node->item;
	free(node);
	Quenue->length--;
	if(Quenue->length == 0)
	{
	    Quenue->front = NULL;
	    Quenue->rear = NULL;
	}
    }
    return ret;
}

void *LinkQuenue_header(LinkQuenue *quenue)
{
    TLinkQuenue *Quenue = (TLinkQuenue *)quenue;
    void *ret = NULL;
    if(Quenue != NULL && Quenue->length > 0)
    {
    	ret = Quenue->front->item;
    }
    return ret ;

}

int LinkQuenue_length(LinkQuenue *quenue)
{
    TLinkQuenue *Quenue = (TLinkQuene *)quenue;
    int ret = -1;
    if( Quenue )
    {
    	ret = Quenue->length;
    }
    return ret ;
}
