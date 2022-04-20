/*********************************************************************************
  *Copyright(C),2022 by JarvisChan
  *FileName: Linked_List.cpp 
  *Author:  JarvisChan//作者
  *Version:  1.0//版本
  *Date:  2022 4.20 16:45//完成日期
  *Description:  to achieve singly_linked list&double_linked list.Also some basic application//用于主要说明此程序文件完成的主要功能
                Application:
                    1.reverse linked list
                    2.delete the Reciprocal N number
                    3.merge two orderly linked list
                //含义及参数间的控制、顺序、独立及依赖关系
  *Others:  //其他内容说明
  *Function List:  //主要函数列表，每条记录应包含函数名及功能简要说明
     1.…………
     2.…………
**********************************************************************************/
#include <stdio.h>
#include "Linked_List.h"
/*
 * struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };
 */

//调用方式，Solution
class Reverse_Solution
{
public:
    //solution1
    ListNode *Reverse_LinkedList_V1(ListNode*head){
        ListNode* cur = NULL,*pre = head;
        while(pre!=NULL) {
            ListNode *t = pre->next;//t指向pre的下一个位置,先记录一下位置待会儿过来
            pre->next = cur;//pre的next指针往后指向cur
            cur = pre;//cur追上来
            pre = t;//p向前走到之前标记的“前面”
        }
        return cur;//返回头结点
    }
    //solution2 recursive
    ListNode* Reverse_LinkedList_V2(ListNode*head){
        //先让ret遍历一遍到链表结尾，然后
        if(head==NULL || head->next== NULL)
            return head;
        ListNode*ret = Reverse_LinkedList_V2(head->next);
        head->next->next = head;
        head->next = NULL;
        return ret;
    }
    //solution 3 super double pointer
    ListNode*Reverse_LinkedList_V3(ListNode*head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *cur = head->next;
        ListNode *t = head;//t负责记录cur前面的位置
        while (!(cur->next == NULL)) {
            head->next = cur->next;//先为cur的移动记下位置
            cur->next = t;//cur往回指
            t = cur;//t走前
            cur = head->next;//cur走前，靠head->next先前帮他记录位置
        }
        head->next = NULL;
        cur->next = t;
        return cur;
    }
};