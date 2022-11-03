package homework;

import java.util.ArrayList;

import homework.Side;

public class Prim {
    public static int closest_j (int i, ArrayList<Side> sides) { //return closest j for i 
        int min=999999;
        int j = -1;
        for (Side side : sides) {
            if (side.getPointA() == i) {
                if (side.getLenth()<min) {
                    min = side.getLenth();
                    j = side.getPointB();      
                }
            }
        }
        return j;
    }

    public static int lenth_point_to_point(int i, int j, ArrayList<Side> sides) {
        for (Side side : sides) {
            if (i == side.getPointA() || j == side.getPointB()) {
                return side.getLenth();
            }
        }
        return -1;
    }

    public static void Prime(int n, ArrayList<Side> sides) {
        int[] s = new int[n+1];
        s[1] = 1;
        int count = 0;
        int[] closest = new int[n+1];
        int[] lowcost = new int[n+1];
        while (count != n) {
            for (int i = 1; i <= s.length; i++) {
                if (s[i] == 1) {
                    closest[i] = closest_j(i, sides);
                    lowcost[i] = lenth_point_to_point(i, closest[i], sides);
                }
            }
        }

    }
    public static void main(String[] args) {
        
    }
}
