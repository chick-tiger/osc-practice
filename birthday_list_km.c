#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/types.h>
struct birthday {
	int day;
	int month;
	int year;
	struct list_head list;
}

static LIST_HEAD(birthday_list);

int cjLinkedList_init(void){
	printk(KERN_INFO "Creating Birthday list\n");
	struct birthday *Kevin;
	Kevin  = kmalloc(sizeof(*Kevin), GFP_KERNEL);
	Kevin->day = 2;
	Kevin->month = 8;
	Kevin->year = 1982;
	INIT_LIST_HEAD(&Kevin->list);
	list_add_tail(&Kevin->list, &birthday_list);

	struct birthday *David;
	David = kmalloc(sizeof(*David), GFP_KERNEL);
	David->day = 1;
	David->month = 6;
	David->year = 1981;
	INIT_LIST_HEAD(&David->list);
	list_add_tail(&David->list, &birthday_list);

	struct birthday *Justin;
	Justin = kmalloc(sizeof(*Justin), GFP_KERNEL);
	Justin->day = 3;
	Justin->month = 7;
	Justin->year = 1983;
	INIT_LIST_HEAD(&Justin->list);
	list_add_tail(&Justin->list, &birthday_list);


	struct birthday *Andy;
	Andy = kmalloc(sizeof(*Andy), GFP_KERNEL);
	Andy->day = 4;
	Andy->month = 9;
	Andy->year = 1984;
	INIT_LIST_HEAD(&Andy->list);
	list_add_tail(&Andy->list, &birthday_list);

	struct birthday *Sean;
	Sean = kmalloc(sizeof(*Sean), GFP_KERNEL);
	Sean->day = 5;
	Sean->month = 10;
	Sean->year = 1985;
	INIT_LIST_HEAD(&Sean->list);
	list_add_tail(&Sean->list, &birthday_list);

	printk(KERN_INFO "Traversing birthday list\n");
	struct birthday *ptr;
	list_for_each_entry(ptr, &birthday_list, list){
		printk(KERN_INFO "BIRTHDAY: Month: %d Day: %d Year: %d\n", ptr->month, ptr->day, ptr->year);
	}
	return 0;
}


void delete_list(void){
	printk(KERN_INFO "Removing Birthday list elements\n");
	struct birthday *ptr, *next;
	list_for_each_entry_safe(ptr, next, &birthday_list, list){
		list_del(&ptr->list);
		kfree(ptr);
	}
}

module_init(print_list);
module_exit(delete_list);

MODULE LICENSE("GPL"); 
MODULE DESCRIPTION("Simple Module"); 
MODULE AUTHOR("SGG");
