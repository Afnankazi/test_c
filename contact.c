#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for Contact
struct Contact {
    char name[50];
    char phone[15];
    struct Contact* next;
};

// Function prototypes
struct Contact* createContact(char name[], char phone[]);
void addContact(struct Contact** head, char name[], char phone[]);
void displayContacts(struct Contact* head);
void deleteContact(struct Contact** head, char name[]);
void searchContact(struct Contact* head, char name[]);
void printMenu();

// Main function
int main() {
    struct Contact* head = NULL;
    int choice;
    char name[50], phone[15];

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the buffer for new input

        switch (choice) {
            case 1:
                printf("\nEnter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                addContact(&head, name, phone);
                printf("\nContact added successfully!\n");
                break;

            case 2:
                printf("\n--- Contact List ---\n");
                displayContacts(head);
                break;

            case 3:
                printf("\nEnter name of the contact to delete: ");
                scanf("%s", name);
                deleteContact(&head, name);
                printf("\nContact deleted (if it existed)!\n");
                break;

            case 4:
                printf("\nEnter name to search: ");
                scanf("%s", name);
                searchContact(head, name);
                break;

            case 5:
                printf("\nExiting the program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

// Function to print menu
void printMenu() {
    printf("\n========================\n");
    printf("    Contact Manager\n");
    printf("========================\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Search Contact\n");
    printf("5. Exit\n");
    printf("========================\n");
}

// Function to create a new contact
struct Contact* createContact(char name[], char phone[]) {
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;
    return newContact;
}

// Function to add a contact
void addContact(struct Contact** head, char name[], char phone[]) {
    struct Contact* newContact = createContact(name, phone);
    if (*head == NULL) {
        *head = newContact;
    } else {
        struct Contact* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newContact;
    }
}

// Function to display all contacts
void displayContacts(struct Contact* head) {
    if (head == NULL) {
        printf("No contacts to display.\n");
        return;
    }
    struct Contact* temp = head;
    while (temp != NULL) {
        printf("Name: %s | Phone: %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

// Function to delete a contact by name
void deleteContact(struct Contact** head, char name[]) {
    struct Contact* temp = *head;
    struct Contact* prev = NULL;

    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to search for a contact by name
void searchContact(struct Contact* head, char name[]) {
    struct Contact* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("\nContact found!\nName: %s | Phone: %s\n", temp->name, temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("\nContact not found.\n");
}
