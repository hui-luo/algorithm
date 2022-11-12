package homework;

public class Side {
    private int pointA;
    private int pointB;
    private int lenth;
    public int getPointA() {
        return pointA;
    }
    public void setPointA(int pointA) {
        this.pointA = pointA;
    }
    public int getPointB() {
        return pointB;
    }
    public void setPointB(int pointB) {
        this.pointB = pointB;
    }
    public int getLenth() {
        return lenth;
    }
    public void setLenth(int lenth) {
        this.lenth = lenth;
    }
    public Side(int pointA, int pointB, int lenth) {
        this.pointA = pointA;
        this.pointB = pointB;
        this.lenth = lenth;
    }
    public Side() {
    }
    @Override
    public String toString() {
        return "point [pointA=" + pointA + ", pointB=" + pointB + ", lenth=" + lenth + "]";
    }
    
}
