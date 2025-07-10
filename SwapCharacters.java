import java.util.Scanner;

class SwapCharacters {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // Input two characters
        System.out.print("Enter the first character: ");
        char ch1 = in.next().charAt(0); // Reads the first character

        System.out.print("Enter the second character: ");
        char ch2 = in.next().charAt(0); // Reads the second character

        // Display before swapping
        System.out.println("\nBefore Swapping:");
        System.out.println("ch1 = " + ch1);
        System.out.println("ch2 = " + ch2);

        // Swap using a temporary variable
        char temp = ch1;
        ch1 = ch2;
        ch2 = temp;

        // Display after swapping
        System.out.println("\nAfter Swapping:");
        System.out.println("ch1 = " + ch1);
        System.out.println("ch2 = " + ch2);
    }
}
