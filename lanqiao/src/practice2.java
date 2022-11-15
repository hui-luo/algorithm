import java.text.NumberFormat;
import java.util.Scanner;

public class practice2 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        //在此输入您的代码...
        int n = scan.nextInt();
        float count1 = 0, count2 = 0;
        int[] score = new int[n];
        for (int i = 0; i < n; i++) {
            score[i] = scan.nextInt();
        }
        for (int i : score) {
            if (i >= 60 && i < 85) {
                count1++;
            }
            else if (i >= 85) {
                count1++;
                count2++;
            }
        }
        NumberFormat format = NumberFormat.getPercentInstance();
        format.setMaximumFractionDigits(0);
        System.out.println(format.format(count1/n));
        System.out.println(format.format(count2/n));

        scan.close();
    }
}
