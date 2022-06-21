//add git test line.

struct chartable
{
    char data;
    struct chartable* next;
};

void tableinsert(char s, struct chartable* head)
{
    struct chartable* temp;
    temp = malloc(sizeof(struct chartable));
    memset(temp, 0, sizeof(struct chartable));
    temp->data = s;
    
    if(head->next == NULL)
    {
        head->next = temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
    }
}

bool tablecheck(char s, struct chartable* head)
{
    int index;
    char defs[6] = {')', '}', ']', '(', '{', '['};
    struct chartable* temp = head->next;
    
    if(head->next == NULL)
        return false;
    
    for (index = 0; index < 3; index++)
    {
        if(s == defs[index])
        {
            if(temp->data != defs[index+3])
            {
                printf("do not match \n");
                return false;
            }
            else
            {
                printf("match %c \n", temp->data);
                head->next = temp->next;
                free(temp);
                return true;
            }
        }
    }
    return true;
}


bool isValid(char* s) {
    int length = 0;
    struct chartable* head = NULL;
    int index = 0;
    char curstr = '0';
    
    head = malloc(sizeof(struct chartable));
    memset(head, 0, sizeof(struct chartable));
    
    length = strlen(s);
    
    if(length%2 != 0)
        return false;
    		    
    for(index = 0; index < (length); index++)
    {
        curstr = *(char*)(s+index);
        printf("curstr %c \n", curstr);
        if((curstr == '(')
           ||(curstr == '{')
           ||(curstr == '['))
        {
            tableinsert(curstr, head);
        }
        else
        {
            if(tablecheck(curstr, head) == false)
            {
                free(head);
                return false;
            }
        }
    }
    if(head->next != 0)
        return false;
    else
        return true;
}
