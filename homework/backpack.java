public class backpack {
    public static void main(String[] args) {
//        int[] wt = {2,3,4,5};
        int[] wt = {4,5,4,1};
//        int[] val = {3,4,5,8};
        int[] val = {6,2,1,8};
        int size = 6;
        int result = knapsackProblem(wt, val, size);
        System.out.println(result);
    }
    public static int knapsackProblem(int[] wt,int[] val,int size){
        //定义dp数组
        int[][] dp = new int[wt.length+1][size+1];
        //对于装入前0个物品而言，dp数组储存的总价值初始化为0
        for(int i = 0;i < size;i++){
            dp[0][i] = 0;
        }
        //对于背包容量W=0时，装入背包的总价值初始化为0
        for(int j = 0;j < wt.length;j++){
            dp[j][0] = 0;
        }
        //外层循环遍历物品0~wt.length
        for(int i = 1;i <= wt.length;i++){
            //内层循环遍历1~W(背包容量)
            for(int j = 1;j <= size;j++){
                //外层循环i,如果第i个物品质量大于当前背包容量
                if (wt[i-1] > j) {
                    dp[i][j] = dp[i-1][j];  //如果当前物品重量大于背包的空间：继承上一个结果
                } else {
                    //在“上一个结果价值”和“把当前第i个物品装入背包里+放入背包后剩余空间最大值”二者里选价值较大的
                    dp[i][j] = Math.max(dp[i-1][j],dp[i-1][j-wt[i-1]] + val[i-1]);
                }
            }
        }
        for (int i = 0; i < wt.length+1; i ++) {
            for (int j = 0; j < size+1; j++) {
                System.out.print("\t" + dp[i][j]);
            }
            System.out.println();
        }
        return dp[wt.length][size];
    }

    public static int func(int[] val, int[] weight, int W) {
        int N = weight.length;   //记录所有的物品数
        int[][] V = new int[N + 1][W + 1];  //创建背包矩阵
        //初始化矩阵 列，背包容量为0
        for (int col = 0; col <= W; col++) {
            V[0][col] = 0;
        }
        for (int row = 0; row <= N; row++) {
            V[row][0] = 0;
        }
        for (int i = 1; i <= N; i++) {  //一行一行填充值
            for (int j = 1; j <= W; j++) {  //一列一列填充值
                if (weight[i - 1] <= j) {  //如果当前物品重量小于等于背包中的当前重量 i为1是，weight[0]是第一个物品的重量
                    //比较不加入该物品时该重量的最大价值（前一行）与当前物品的价值+可以容纳的剩余重量的价值
                    V[i][j] = Math.max(val[i-1] + V[i-1][j - weight[i-1]],V[i-1][j]);
                } else { //如果当前物品重量大于背包中的当前重量
                    V[i][j]=V[i-1][j];  //直接使用前一行的最优解
                }
            }
        }
//        /打印矩阵
        for (int[] rows: V) {
            for (int col : rows) {
                System.out.format("%5d",col);
            }
            System.out.println();
        }
        return V[N][W];

    }

}
