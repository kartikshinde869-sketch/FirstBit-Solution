#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    int Book_ID;
    char Book_Name[100];
    char Author_Name[50];
    char Category[50];
    float Price;
    float Rating;
} Book;


Book* addBook(Book B[], int *count, int *max);
void removeBook(Book B[], int *count);
void searchBook(Book B[], int count);
void updateBook(Book B[], int count);
void displayAll(Book B[], int count);
void displaySortedBooks(Book B[], int count);
void showAuthorsBooks(Book B[], int count);
void showCategoryBooks(Book B[], int count);

int main() {
    int max = 10;
    Book* B = (Book*)malloc(sizeof(Book) * max);
    int count = 10;
    int choice = 0;
    
    B[0] = (Book){101, "The Alchemist", "Paulo Coelho", "Fiction", 250.0, 4.8};
    B[1] = (Book){102, "Atomic Habits", "James Clear", "Self-help", 350.0, 4.7};
    B[2] = (Book){103, "Rich Dad Poor Dad", "Robert Kiyosaki", "Finance", 400.0, 4.5};
    B[3] = (Book){104, "The Silent Patient", "Alex Michaelides", "Thriller", 300.0, 4.2};
    B[4] = (Book){105, "Educated", "Tara Westover", "Biography", 450.0, 4.6};
    B[5] = (Book){106, "Sapiens", "Yuval Noah Harari", "History", 500.0, 4.9};
    B[6] = (Book){107, "The Power of Habit", "Charles Duhigg", "Self-help", 320.0, 4.4};
    B[7] = (Book){108, "Harry Potter", "J.K. Rowling", "Fantasy", 600.0, 4.9};
    B[8] = (Book){109, "The Subtle Art of Not Giving a F*ck", "Mark Manson", "Self-help", 280.0, 4.3};
    B[9] = (Book){110, "Thinking, Fast and Slow", "Daniel Kahneman", "Psychology", 550.0, 4.6};

    while(choice != 9) {
        printf("\n--- Book Management System ---\n");
        printf("1. Add Book\n2. Remove Book\n3. Search Book\n");
        printf("4. Update Book Data\n5. Display All Books\n6. Display Sorted Books\n");
        printf("7. Show Author's Books\n8. Show Category's Books\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: B = addBook(B, &count, &max); break;
            case 2: removeBook(B, &count); break;
            case 3: searchBook(B, count); break;
            case 4: updateBook(B, count); break;
            case 5: displayAll(B, count); break;
            case 6: displaySortedBooks(B, count); break;
            case 7: showAuthorsBooks(B, count); break;
            case 8: showCategoryBooks(B, count); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    }

    free(B);
    return 0;
}


Book* addBook(Book B[], int *count, int *max) {
    if(*count >= *max) {
        *max *= 2;
        B = (Book*)realloc(B, sizeof(Book) * (*max));
    }
    int id, duplicate = 0;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    // Check for duplicate Book ID
    for(int i = 0; i < *count; i++) {
        if(B[i].Book_ID == id) {
             printf("Duplicate Book ID! Book not added.\n");
            return B;
        }
    }

    

    printf("Enter Book ID: "); scanf("%d", &B[*count].Book_ID);
    printf("Enter Book Name: "); scanf(" %[^\n]", B[*count].Book_Name);
    printf("Enter Author Name: "); scanf(" %[^\n]", B[*count].Author_Name);
    printf("Enter Category: "); scanf(" %[^\n]", B[*count].Category);
    printf("Enter Price: "); scanf("%f", &B[*count].Price);
    printf("Enter Rating: "); scanf("%f", &B[*count].Rating);

    (*count)++;
    printf("Book added successfully!\n");
    return B;
}


void removeBook(Book B[], int *count) {
    if(*count == 0) { printf("No books available.\n"); return; }
    int id, found = 0;
    printf("Enter Book ID to remove: "); scanf("%d", &id);

    for(int i = 0; i < *count; i++) {
        if(B[i].Book_ID == id) {
            for(int j = i; j < *count - 1; j++){
			 B[j] = B[j + 1];
		}
            (*count)--; 
			found = 1;
            printf("Book removed successfully!\n"); break;
        }
    }
    if(found==0) 
	printf("Book not found.\n");
}


void searchBook(Book B[], int count) {
    if(count == 0) { 
	printf("No books available.\n"); 
	return; 
	}
    int choice, id, found = 0;
    char name[100];
    printf("Search by 1. ID 2. Name: ");
	scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter Book ID: "); 
		scanf("%d", &id);
        for(int i = 0; i < count; i++) {
            if(B[i].Book_ID == id) {
                printf("\nBook Found:\nID: %d\nName: %s\nAuthor: %s\nCategory: %s\nPrice: %.2f\nRating: %.1f\n",
                       B[i].Book_ID, B[i].Book_Name, B[i].Author_Name, B[i].Category, B[i].Price, B[i].Rating);
                found = 1;
				 break;
            }
        }
    } else if(choice == 2) {
        printf("Enter Book Name: "); 
		scanf(" %[^\n]", name);
        for(int i = 0; i < count; i++) {
            if(strcmp(B[i].Book_Name, name) == 0) {
                printf("\nBook Found:\nID: %d\nName: %s\nAuthor: %s\nCategory: %s\nPrice: %.2f\nRating: %.1f\n",
                       B[i].Book_ID, B[i].Book_Name, B[i].Author_Name, B[i].Category, B[i].Price, B[i].Rating);
                found = 1; 
				break;
            }
        }
    } else { printf("Invalid choice.\n"); return; }

    if(!found) printf("Book not found.\n");
}

// Update Price or Rating
void updateBook(Book B[], int count) {
    if(count == 0) {
	 printf("No books available.\n"); 
	 return;
	  }
    int id, choice, found = 0;
    float value;
    printf("Enter Book ID to update: "); 
	scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(B[i].Book_ID == id) {
            printf("Update 1. Price 2. Rating: "); 
			scanf("%d", &choice);
            if(choice == 1) { 
			printf("Enter new Price: "); 
			scanf("%f", &value); 
			B[i].Price = value;
			 }
            else if(choice == 2) {
			 printf("Enter new Rating: "); 
			 scanf("%f", &value); 
			 B[i].Rating = value; 
			 }
            else { 
			printf("Invalid choice\n"); 
			return; 
			}
            printf("Book updated successfully!\n");
            found = 1; 
			break;
        }
    }
    if(!found) 
	printf("Book not found.\n");
}

// Display all books
void displayAll(Book B[], int count)
 {
    if(count == 0) {
	 printf("No books available.\n");
	  return;
	   }
    for(int i = 0; i < count; i++)
        printf("\nID: %d | Name: %s | Author: %s | Category: %s | Price: %.2f | Rating: %.1f\n",
               B[i].Book_ID, B[i].Book_Name, B[i].Author_Name, B[i].Category, B[i].Price, B[i].Rating);
}

// Display sorted books
void displaySortedBooks(Book B[], int count)
 {
    if(count == 0) {
	 printf("No books available.\n"); 
	 return;
	  }
    Book temp, copy[count];

    for(int i = 0; i < count; 
	i++) copy[i] = B[i];

    // Sort by Price descending
    for(int i = 0; i < count - 1; i++)
        for(int j = 0; j < count - i - 1; j++)
            if(copy[j].Price < copy[j+1].Price) {
			 temp = copy[j]; 
			 copy[j] = copy[j+1];
			  copy[j+1] = temp; 
			  }

    printf("\n--- Books Sorted by Price (High to Low) ---\n");
    for(int i = 0; i < count; i++)
        printf("ID: %d | %s | Price: %.2f\n", copy[i].Book_ID, copy[i].Book_Name, copy[i].Price);

    // Sort by Rating descending
    for(int i = 0; i < count - 1; i++)
        for(int j = 0; j < count - i - 1; j++)
            if(copy[j].Rating < copy[j+1].Rating) {
			 temp = copy[j]; 
			 copy[j] = copy[j+1]; 
			 copy[j+1] = temp; 
			 }

    printf("\n--- Books Sorted by Rating (High to Low) ---\n");
    for(int i = 0; i < count; i++)
        printf("ID: %d | %s | Rating: %.1f\n", copy[i].Book_ID, copy[i].Book_Name, copy[i].Rating);
}

// Show books by author
void showAuthorsBooks(Book B[], int count) {
    if(count == 0) { 
	printf("No books available.\n");
	 return; 
	 }
    char author[50];
    int found = 0;
    printf("Enter Author Name: ");
	 scanf(" %[^\n]", author);

    for(int i = 0; i < count; i++) {
        if(strcmp(B[i].Author_Name, author) == 0) {
            printf("ID: %d | %s | Category: %s | Price: %.2f | Rating: %.1f\n",
                   B[i].Book_ID, B[i].Book_Name, B[i].Category, B[i].Price, B[i].Rating);
            found = 1;
        }
    }
    if(!found) 
	printf("No books found for this author.\n");
}

// Show books by category
void showCategoryBooks(Book B[], int count) {
    if(count == 0)
	 { 
	 printf("No books available.\n");
	  return;
	   }
    char category[50];
    int found = 0;
    printf("Enter Category: "); 
	scanf(" %[^\n]", category);

    for(int i = 0; i < count; i++) {
        if(strcmp(B[i].Category, category) == 0) {
            printf("ID: %d | %s | Author: %s | Price: %.2f | Rating: %.1f\n",
                   B[i].Book_ID, B[i].Book_Name, B[i].Author_Name, B[i].Price, B[i].Rating);
            found = 1;
        }
    }
    if(!found)
	printf("No books found in this category.\n");
}