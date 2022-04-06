#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
* See list.h for expected behavior of functions
**/

typedef struct node {
    ElemType val;
    struct node *next;
} NODE;


struct list_struct {
    NODE *front;
    NODE *back;
    int size;
};


/*
* returns pointer to newly created empty list
*/
LIST *lst_create() {
    LIST *l = malloc(sizeof(LIST));

    l->front = NULL;
    l->back = NULL;
    return l;
}

// used to free nodes in a list and then free the list
void lst_free(LIST *l) {
    NODE *p = l->front;
    NODE *pnext;

    while(p != NULL) {
        pnext = p->next;   // keeps us from de-referencing a freed ptr
        free(p);
        p = pnext;
        l -> size--;
    }
    // now free the LIST
    free(l);
}

// used to print the list
void lst_print(LIST *l) {
    NODE *p = l->front;

    printf("[");
    while(p != NULL) {
        printf(FORMAT, p->val);
        p = p->next;
    }
    printf("]\n");
}


/**
* TODO:  
*   function:  lst_are_equal
*   description:  returns true(1) if lst1 and lst2
*      contain exactly the same sequenc of values.
*      Returns 0 otherwise.
**/
int lst_are_equal(LIST *lst1, LIST *lst2) {
    NODE *curr1 = lst1 -> front;
    NODE *curr2 = lst2 -> front;

    // accounting for empty lists
    if (lst1 -> front == NULL && lst2 -> front == NULL) {
        return 1;
    }
    if (lst1 -> front == NULL || lst2 -> front == NULL) {
        return 0;
    }

    // going through both lists and checking if they are the same
    while (curr1 != NULL && curr2 != NULL) {
        if (curr1 -> val != curr2 -> val) {
            return 0;
        }
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }
    // account for if not the same size
    if (curr1 != NULL || curr2 != NULL) {
        return 0;
    }
    return 1;
}

// prints linked list in reverse
// uses recursion
void printReverse(NODE * curr) {
    if (curr == NULL) {
        return;
    }
    printReverse(curr -> next);

    printf(FORMAT, curr -> val);
}

/**
* TODO:  print in reverse order 
*
* Try to do without looking at notes!
* Hints:  recursive helper function
*/
void lst_print_rev(LIST *l) {
    if (l -> front == NULL) {
        return;
    }
    printReverse(l -> front);
}

void lst_push_front(LIST *l, ElemType val) {
    NODE *p = malloc(sizeof(NODE));

    p->val = val;
    p->next = l->front;
  
    l->front = p;
    l -> size = l -> size + 1;
    if(l->back == NULL)   // was empty, now one elem
        l->back = p;
}

void lst_push_back(LIST *l, ElemType val) {
    NODE *p;

    if(l->back == NULL || l->front == NULL)   // list empty - same as push_front
	    lst_push_front(l, val);
    else {  // at least one element before push
        p = malloc(sizeof(NODE));
        p->val = val;
        p->next = NULL;
        l->back->next = p;
        l -> size = l -> size + 1;
        l->back = p;
    }
}

/** TODO 
*   modifications to enable this operation
*   to execute in O(1) time.  (You will almost
*   certainly modify other functions and the 
*   data structure itself -- see header).
**/
int lst_length(LIST *l) {
  return l -> size;
}

int lst_is_empty(LIST *l) {
  return l->front == NULL;
}


/** TODO
 *    function:  lst_count
*     description:  Counts number of occurrences 
*     		of x in the list and returns 
*     		that value.
*/
int lst_count(LIST *l, ElemType x) {
    int countX = 0;
    NODE *curr = l -> front;
    while (curr != NULL) {
        if (curr -> val == x) {
            countX++;
        }
        curr = curr -> next;
    }

    return countX;
}


/* These are "sanity checker" functions that check to see
*     list invariants hold or not.
*/
int lst_sanity1(LIST *l) {
    if(l->front == NULL && l->back != NULL){
        fprintf(stderr, "lst_sanity1 error:  front NULL but back non-NULL\n");
        return 0;
    }
    if(l->back == NULL && l->front != NULL){
        fprintf(stderr, "lst_sanity1 error:  back NULL but front non-NULL\n");
        return 0;
    }
    return 1;
}

int lst_sanity2(LIST *l) {
    if(l->back != NULL && l->back->next != NULL) {
	    fprintf(stderr, "lst_sanity2 error:  back elem has a non-NULL next?\n");
	    return 0;
    }
    return 1;
}

/*
* function:  find_back()
* description:  returns a pointer to the last
*               node of the given list.
*		Note that we are operating at
*		the "node level".
*
*		if p is NULL, NULL is returned.
*
* purpose:  mostly for debugging -- enables sanity3
*/
static NODE * find_back(NODE *p) {
    if(p ==  NULL)
        return NULL;

    while(p->next != NULL) {
        p = p->next;
    }
    return p;
}

/*
*   makes sure that the back pointer is also the last reachable
*    node when you start walking from front.
*    HINT:  use pointer comparison
*/
int lst_sanity3(LIST *l) {
    NODE *real_back;

    real_back = find_back(l->front);

    return (real_back == l->back);
}



ElemType lst_pop_front(LIST *l) {
    ElemType ret;
    NODE *p;

    l -> size = l -> size - 1;
      if(lst_is_empty(l))
        return DEFAULT;   // no-op

      ret = l->front->val;

      if(l->front == l->back) {  // one element
        free(l->front);
        l->front = NULL;
        l->back = NULL;
      }
      else {
        p = l->front;  // don't lose node being deleted
        l->front = l->front->next;  // hop over
        free(p);
      }
      return ret;
}

     
  


/* TODO 
*    
*    if list is empty, we do nothing and return arbitrary value
*    otherwise, the last element in the list is removed and its
*      value is returned.
*
*/
ElemType lst_pop_back(LIST *l) {
    NODE *tempVal = l -> back;
    int val;
    NODE *current = l -> front;
    NODE *prev = l -> front;

    if (lst_is_empty(l)) {
        return DEFAULT;
    } else if (l -> size == 1) {
        l -> front = NULL;
        val = tempVal -> val;
        l -> size = l -> size - 1;
        return val;
    } else {
        while (current -> next != NULL) {
            prev = current;
            current = current -> next;
        }
        prev -> next = NULL;
        val = tempVal -> val;
        free(tempVal);
        l -> size = l -> size - 1;
        return val;
    }
} 

/* TODO
*  For full credit, you cannot allocate any new memory!
*
*  description:  self-evident 
*/
void lst_reverse(LIST *l) {
    NODE *prev = NULL;
    NODE *current = l -> front;
    NODE *next = NULL;

    // list empty
    if (current == NULL) {
        return;
    }
    // one node does not need to be reversed
    if (current -> next == NULL) {
        return;
    }
    l -> back = l -> front;
    while (current != NULL) {
        // Store next
        next = current -> next;

        // Reverse current node's pointer
        current -> next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    l -> front = prev;
}


/*
* removes first occurrence of x (if any).  Returns
*   0 or 1 depending on whether x was found
*/
int lst_remove_first(LIST *l, ElemType x) {
    NODE *p;
    NODE *tmp;

    if(l->front == NULL) return 0;
    if(l->front->val == x) {
        lst_pop_front(l);
        return 1;
    }
    // lst non-empty; no match on 1st elem
    p = l->front;

    while(p->next != NULL) {
        if(x == p->next->val) {
            tmp = p->next;
            p->next = tmp->next;
            if(tmp == l->back)
                l->back = p;
            free(tmp);
            l -> size = l -> size - 1;
            return 1;
         }
            p = p->next;
    }
    return 0;
}


/**
* function: lst_remove_all_slow
* description:  removes all occurrences of x
*   from given list (if any).
*   Returns number of occurrences (i.e., deletions).
* 
* notes:  it is called "slow" because in the worst
*   case, it takes quadratic time.
*   (Discussion of why and when this happens is a
*   lecture topic).
*/
int lst_remove_all_slow(LIST *l, ElemType x) {
  int n=0;
  while(lst_remove_first(l, x)) {
      n++;
      l -> size = l -> size - 1;
  }
  return n;
}

/** 
 * function: lst_sra_bad_case (sra:  slow_remove_all)
 *
 * description: constructs a list of length n such that 
 * the above function takes quadratic time to remove
 * all occurrences of a specified value. 
 *
 * By convention, the specified value will be 0
 */
LIST *lst_sra_bad_case(int n) {
    LIST *l = lst_create();
    int i;
    int k=n/2;

      for(i=0; i<k; i++) {
        lst_push_front(l, 0);
      }
      for(i=0; i<n-k; i++) {
        lst_push_front(l, 1);
      }
      return l;
}

/** TODO
*   function:  lst_remove_all_fast
*   description:  same behavior/semantics as
*      lst_remove_all_slow.  However, this function
*      must guarantee linear time worst case 
*      runtime (hence, "fast").
*
*   REQUIREMENT:  linear worst-case runtime.
*
*   Note:  your solution may be either recursive or 
*   iteratieve.
**/
int lst_remove_all_fast(LIST *l, ElemType x) {
    NODE *temp;
    NODE *curr = l -> front;
    int n = 0;

    while(curr != NULL) {
        temp = curr;
        curr = curr -> next;
        free(temp);
        l -> size = l -> size - 1;
        n++;
    }
    l -> front = NULL;
    l -> back = NULL;
    l -> size = 0;
  return n;
}

// checking to see if list is sorted
// returns 0 if not sorted and true if it is sorted
int lst_is_sorted(LIST *l){
    NODE *p = l->front;

    while(p!=NULL && p->next != NULL) {
        if(p->val > p->next->val)
          return 0;
        p = p->next;
    }
    return 1;
}



/** TODO
* function:  lst_insert_sorted
*
* description:  assumes given list is already in sorted order
*	   and inserts x into the appropriate position
* 	   retaining sorted-ness.
* Note 1:  duplicates are allowed.
*
* Note 2:  if given list not sorted, behavior is undefined/implementation
* 		dependent.  We blame the caller.
* 		So... you don't need to check ahead of time if it is sorted.
*/
void lst_insert_sorted(LIST *l, ElemType x) {
    NODE *curr = l -> front;
    NODE *temp = l -> front;

    // empty list
    // inserting as first node in list
    if (curr == NULL) {
        NODE *p = malloc(sizeof(NODE));
        p -> val = x;
        p -> next = NULL;
        l -> front = p;
        l -> back = p;
        l -> size = l -> size + 1;
        return;
    }
    // x is less than first node
    // inserting at beginning of list
    if (curr -> val >= x) {
        NODE *p = malloc(sizeof(NODE));
        p -> val = x;
        p -> next = curr;
        l -> front = p;
        l -> size = l -> size + 1;
        return;
    }

    // greater than back node so inserts at back of list
    if (l -> back -> val < x) {
        while (curr -> next != NULL) {
            curr = curr -> next;
        }

        NODE *p = malloc(sizeof(NODE));
        l -> back = p;
        p -> val = x;
        p -> next = NULL;
        curr -> next = p;
        l -> size++;
        return;
    }

    // checking to see where to insert in linked list
    while (curr -> next -> val <= x && curr -> next != NULL) {
        curr = curr -> next;
    }
    NODE *p = malloc(sizeof(NODE));
    temp = curr -> next;
    curr -> next = p;
    p -> next = temp;
    p -> val = x;
    l -> size++;
}

/** TODO
 * function:  lst_merge_sorted
 *
 * description:  assumes both list a and b are in
 * 	sorted (non-descending) order and merges them
 * 	into a single sorted list with the same
 * 	elements.  
 *
 * 	This single sorted list is stored in a while
 * 	b becomes empty.
 *
 * 	if either of given lists are not sorted, 
 * 	we blame the caller and the behavior is
 * 	implementation dependent -- i.e., don't worry
 * 	about it!
 *
 * 	Example:
 *
 * 		a:  [2 3 4 9 10 30]
 * 		b:  [5 8 8 11 20 40]
 *
 * 		after call on (a,b)
 *
 * 		a:  [2 3 4 5 8 8 9 10 11 20 30 40]
 * 		b:  []
 * 
 * implementation:  should not allocate ANY new list
 * 	nodes -- it should just re-link existing
 * 	nodes.
 *
 * 	Must be linear time in the |a|+|b| -- i.e.,
 * 	the total number of elements being processed.
 */
void lst_merge_sorted(LIST *a, LIST *b){
    NODE *prevA = a -> front;
    NODE *currA = a -> front;
    NODE *prevB = b -> front;
    NODE *currB = b -> front;

    // checks for empty lists
    if (a -> front == NULL) {
        a -> front = b -> front;
        return;
    }
    if (b -> front == NULL) {
        a -> front = a -> front;
        return;
    }

    // inserting in front
    if (currB -> val < currA -> val) {
        currB = currB -> next;
        a -> front = prevB;
        prevB -> next = currA;
        prevB = currB;
        prevA = currA;
        currA = currA -> next;
        a -> size = a -> size + 1;
    }

    // checking to see where to merge each element in list b into list a
    while (currA != NULL && currB != NULL) {
        if (currB -> val <= currA -> val) {
            currB = currB -> next;
            prevA -> next = prevB;
            prevB -> next = currA;
            prevB = currB;
            a -> size = a -> size + 1;
        } else {
            prevA = currA;
            currA = currA -> next;
        }
   }
    // used for when listB elements are bigger than listA last node
    if (currB != NULL) {
        prevA -> next = prevB;
    }
}

/**
* TODO
* function:  lst_clone
*
* description:  makes a "deep copy" of the given list a
*   and returns it (as a LIST pointer).
*
*/
LIST * lst_clone(LIST *a) {
    // allocating new memory for deep copy
    LIST *copy = malloc(sizeof(LIST));
    // checking for empty list
    if(a == NULL) {
        copy = NULL;
    }
    else {
        NODE *temp = a->front;
        // copying over all the nodes from one list to the other
        while (temp != NULL) {
            (lst_push_back(copy, temp->val));
            temp = temp->next;
        }
    }

  return copy;
}



/**
* TODO
* function:  lst_from_array 
*
* description:  creates a new list populated with the
*      elements of array a[] in the same order as 
*      they appear in a[] (element at a[0] will be the
*      first element in the list and so-on).  List is
*      returned as a LIST pointer.
*
*      Parameter n indicates the length of the given array.
*
* runtime requirement:  THETA(n)
*/
LIST * lst_from_array(ElemType a[], int n){
    LIST *theList = lst_create();
    NODE *curr;
    // going through each element in array and pushing it back into a linked list
    for (int i = 0; i < n; i++) {
        lst_push_back(theList, a[i]);
    }
  return theList;
}


/**
* TODO
* function:  lst_to_array 
*
* description:  allocates an array of ElemType and populates
*         it with the elements in the given list (as with
*         lst_from_array elements are in the same order in
*         both data structures).
*
* runtime requirement:  THETA(n)
*
*/
ElemType * lst_to_array(LIST *lst) {
    NODE * curr = lst -> front;
    int size = lst -> size;
    ElemType *theArray= malloc(size * sizeof(ElemType));
    int count = 0;

    // going through each node and adding that node value into the array
    while (curr != NULL) {
        theArray[count] = curr -> val;
        count++;
        curr = curr -> next;
    }

  return theArray;
}


/**
* TODO
* function:  lst_prefix
*
* description:  removes the first k elements from the
*               given list which are used to form a new list
*		which is then returned.
*
*		if n is the length of the given list, we have the
*		following boundary conditions:
*
*		  if k==0:
*			lst unchanged and an empty list returned
*		  if k>=n:
*			lst becomes empty and a list containing
*			all elements previously in lst is returned.
*
*		examples:
*
*		  EX1:  lst:  [2, 3, 9, 7, 8]
*			k:    3
*
*			after call:
*			   lst:  [7, 8]
*			   returned list:  [2, 3, 9]
*
*		  EX2  lst:  [2, 3, 9, 7, 8]
*			k:    0
*
*			after call:
*			   lst:  [2, 3, 9, 7, 8]  (unchanged)
*			   returned list:  []
*
*		  EX3  lst:  [2, 3, 9, 7, 8]
*			k:    5
*
*			after call:
*			   lst:  []
*			   returned list:  [2, 3, 9, 7, 8]
*
* REQUIREMENTS:
*
*	RUNTIME:  THETA(n) worst case where n is the length of the given list
*
*       ORDERING:  the ordering of the returned prefix should be the same as
*                  in the given list
*
*       MEMORY:    for full credit, no new nodes should be allocated or deallocated;
*		   you should just "re-use" the existing nodes.  HOWEVER, you will
*		   need to allocate a LIST structure itself (i.e., for the returned
*		   list).
*/
LIST * lst_prefix(LIST *lst, unsigned int k) {
    LIST *theList = lst_create();

    // no elements need to be traversed
    if (k == 0) {
        return theList;
    } else if (k >= lst -> size) { // wants the whole list
        theList = lst;
        lst_free(lst);
    } else {
        NODE *curr = lst->front;
        NODE *curr1 = theList->front;
        theList->front = curr;
        // used to add the nodes into list until the k point
        for (int i = 1; i < k; i++) {
            curr1 = curr;
            curr = curr->next;
            curr1 = curr1->next;
        }
        lst->front = curr1->next;
        curr1->next = NULL;
    }

    return theList;
}


/**
* TODO
* function:  lst_filter_leq
*
* description:  removes all elements of the given list (lst) which
*		are less than or equal to a given value (cutoff)
*		
*		A list containing the removed elements is returned.
*
* examples:
*
*	EX1: 	lst:  [4, 9, 2, 4, 8, 12, 7, 3]
*		cutoff:  4
*
*		after call:
*			lst:  [9, 8, 12, 7]
*			returned list:  [4, 2, 4, 3]
*
*       -----------------------------------------
*	EX2: 	lst:  [6, 5, 2, 1]
*		cutoff:  6
*
*		after call:
*			lst:  []
*	 		returned list:  [6, 5, 2, 1]
*
* REQUIREMENTS:
*
*	RUNTIME:  THETA(n) where n is the length of the given list
*
*       ORDERING:  the ordering of the returned list should be the same as
*                  in the given list
*
*       MEMORY:    for full credit, no new nodes should be allocated or deallocated;
*		   you should just "re-use" the existing nodes.  HOWEVER, you will
*		   need to allocate a LIST structure itself (i.e., for the returned
*		   list).
*			
*/
LIST * lst_filter_leq(LIST *lst, ElemType cutoff) {
    LIST *theList = lst_create();
    LIST *theLst = lst_create();
    NODE *curr = lst -> front;
    NODE *prev = lst -> front;

    // going through each node
    while (curr != NULL) {
        if (curr -> val <= cutoff) {
            lst_push_back(theList, curr -> val);
            prev = curr -> next;
        } else {
            lst_push_back(theLst, curr -> val);
        }
        curr = curr -> next;
    }
    lst_free(lst);
    lst -> front = theLst -> front;

    return theList;
}

/**
* TODO
* function:  lst_concat
*
* description:  concatenates lists a and b; resulting
*    concatenation is reflected in list a; list b becomes
*    empty.
*
*    example:
*
*	EX1:  a: [2, 9, 1]
*	      b: [5, 1, 2]
*
*	after call:
*
*		a: [2, 9, 1, 5, 1, 2]
*		b: []
*
* REQUIREMENTS:  
*
*     runtime:  O(1)
*
*     sanity:  this operation makes sense when a and b
*		are distinct lists.  For example, we don't
*		want/allow the caller to do something like
*		this:
*
*			LIST *my_list;
*
*			lst_push_front(my_lst, 4);
*			lst_push_front(my_lst, 2);
*
*			lst_concat(my_lst, my_lst);
*
*		your implementation must detect if it is being
*		called this way.  If so the function does nothing
*		and (optionally) prints an error message to
*		stderr.
*	
*/
void lst_concat(LIST *a, LIST *b) {
    // checking to make sure not the same lists
    if (a == b) {
        return;
    }
    // checking if list is empty
    if (b -> front == NULL) {
        return;
    }
    // concat a to b if lisA is empty
    if (a -> front == NULL) {
        a -> front = b -> front;
        return;
    }
    // connecting last node in a to list b
    a -> back -> next = b -> front;
    a -> size = a -> size + b -> size;
}

