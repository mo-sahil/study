class PlaceTiles{
    public static int placetiles(int n, int m){
        if(n == m) return 2;

        if(n < m) return 1;

        return placetiles(n-m, m) + placetiles(n-1, m);
    }
    public static void main(String args[]){
        System.out.print(placetiles(4, 2));
    }
}