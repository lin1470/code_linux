package project.data;

import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        System.out.println("Hello World!");
        int n = new Scanner(System.in).nextInt();
        init(n);
    }


        public static int init (int n) {
            factory fat = new factory();
            List<point> pointlist = fat.creatpointlist(n);
            List<line> linelist = fat.creatlinelist(pointlist, n);

            /**
             * 用for 遍历
             */
            System.out.println("for遍历");
            for (int i = 0; i < pointlist.size(); i++) {

                System.out.println(pointlist.get(i).toString());

            }


            /**
             * 用for 遍历
             */
            System.out.println("for遍历");
            for (int i = 0; i < linelist.size(); i++) {

                System.out.println(linelist.get(i).toString());

            }
            return 0;

//

//
//        /**
//         * 用foreach遍历
//         */
//        System.out.println("foreach遍历");
//        for (point item : list
//             ) {
//            System.out.println(item.toString());
//        }
//
//        /**
//         * 取出单独一个元素
//         */
//        System.out.println("单独取得元素");
//        System.out.println(list.get(1).getX());

        }
    }

