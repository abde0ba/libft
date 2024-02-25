#include "libft.h"

void del(void *content)
{
    free(content);
}

int main()
{
    t_list *header = ft_lstnew(NULL);
    t_list *node1 = ft_lstnew(NULL);
    t_list *node3 = ft_lstnew(NULL);
    t_list *node4 = ft_lstnew(NULL);

    node3->content = (char *)malloc(7);
    header->content = "test1";
    node1->content = "test2";
    // node3->content = "test3";
    ft_memcpy(node3->content, "test3", 6);
    node4->content = "test4";
    ft_lstadd_back(&header, node1);
    ft_lstadd_back(&header, node3);
    ft_lstadd_back(&header, node4);
    t_list *current = header;
    // ft_lstdelone(node3, del);
    while (header)
    {
    if (ft_strncmp(header->next->content, "test3", 5) == 0)
        header->next = header->next->next;
    else
    {
        printf("%s\n", (char *)header->content);
        header = header->next;
    }
    }
    // t_list *tmp = header;
    // while (current->next != NULL)
    // {
    //     printf("%s\n", (char *)current->content);
    //     current = current->next;
    // }
    // printf("%s", (char *)node3->content);
}