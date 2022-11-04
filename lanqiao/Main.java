package lanqiao;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        //在此输入您的代码...
        String str = scan.nextLine();
        int[] alphabet = new int[26];
        // System.out.println(alphabet[2]);`
        for (char i : str.toCharArray()) {
            alphabet[i-97]++;
        }
        int max = 0;
        int index = 0;
        for (int i = 0;i < alphabet.length; i++) {
            // System.out.print(i+" ");
            if (alphabet[i] > max) {
                max = alphabet[i];
                index = i;
            }
        }
        System.out.print(Character.toChars(index+97));
        System.out.println();
        System.out.println(alphabet[index]);
        scan.close();
    }
}
