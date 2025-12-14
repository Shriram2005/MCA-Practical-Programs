import java.util.*;

class Book {
    String title;
    String author;
    int publicationYear;
    boolean isAvailable;

    Book(String title, String author, int publicationYear) {
        this.title = title;
        this.author = author;
        this.publicationYear = publicationYear;
        this.isAvailable = true;
    }

    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            System.out.println(title + " has been borrowed.");
        } else {
            System.out.println(title + " is currently unavailable.");
        }
    }

    void returnBook() {
        isAvailable = true;
        System.out.println(title + " has been returned.");
    }

    void displayStatus() {
        System.out.println("Book: " + title + " | Author: " + author +
                " | Year: " + publicationYear +
                " | Available: " + isAvailable);
    }
}

class Member {
    String name;
    int memberId;
    ArrayList<Book> borrowedBooks;

    Member(String name, int memberId) {
        this.name = name;
        this.memberId = memberId;
        borrowedBooks = new ArrayList<>();
    }

    void borrowBook(Book book) {
        if (book.isAvailable) {
            book.borrowBook();
            borrowedBooks.add(book);
        } else {
            System.out.println("Sorry, " + book.title + " is not available.");
        }
    }

    void returnBook(Book book) {
        if (borrowedBooks.remove(book)) {
            book.returnBook();
        } else {
            System.out.println("You did not borrow this book.");
        }
    }

    void displayBorrowedBooks() {
        System.out.println(name + " (ID: " + memberId + ") borrowed:");
        if (borrowedBooks.isEmpty()) {
            System.out.println("No books borrowed.");
        } else {
            for (Book b : borrowedBooks) {
                System.out.println("- " + b.title);
            }
        }
    }
}

public class LibrarySystem {
    public static void main(String[] args) {
        Book b1 = new Book("Java Basics", "James Gosling", 2010);
        Book b2 = new Book("Python Essentials", "Guido van Rossum", 2015);
        Book b3 = new Book("C++ Fundamentals", "Bjarne Stroustrup", 2005);

        Member m1 = new Member("Alice", 101);
        Member m2 = new Member("Bob", 102);

        m1.borrowBook(b1);
        m1.borrowBook(b2);
        m2.borrowBook(b2);

        m1.displayBorrowedBooks();
        m2.displayBorrowedBooks();

        b1.displayStatus();
        b2.displayStatus();
        b3.displayStatus();

        m1.returnBook(b1);
        b1.displayStatus();
    }
}
