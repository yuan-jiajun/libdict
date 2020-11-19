#include <stdlib.h>
#include <stdio.h>
#include <hashtable.h>
#include <string.h>

/**
 * @author Yuan Jiajun
 * @date: 2020/11/19 11:34
 * @description: @link
 */

int main() {
    hashtable *table = hashtable_new((dict_compare_func) strcmp, dict_str_hash, 1);
//    printf("hashtable_count : %zu\n", hashtable_count(table));
//    printf("hashtable_size : %zu\n", hashtable_size(table));



    for (int i = 0; i < 1000; ++i) {
        char key[25];
        sprintf(key, " %d", i);
//        printf("key : %s\n",key);
        hashtable_insert(table, key);
//        printf("hashtable_count : %zu\n", hashtable_count(table));
//        printf("hashtable_size  : %zu\n", hashtable_size(table));
    }


    hashtable_itor *itor = hashtable_itor_new(table);
    hashtable_itor_first(itor);

//    printf("'%s': '%s'\n",
//           (char *) hashtable_itor_key(itor),
//           (char *) *hashtable_itor_datum(itor));


    for (; hashtable_itor_valid(itor); hashtable_itor_next(itor))
        printf("'%s': '%s'\n",
               (char *) hashtable_itor_key(itor),
               (char *) *hashtable_itor_datum(itor));

    hashtable_itor_free(itor);

}