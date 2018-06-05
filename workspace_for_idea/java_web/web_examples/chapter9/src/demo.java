import java.sql.Connection;
import java.sql.Driver;
import java.sql.DriverManager;
import java.sql.SQLException;

import static java.lang.System.out;

/**
 * Created by bruce on 5/16/17.
 */
public class demo {
    public static void main(String args[]) throws SQLException, ClassNotFoundException {
        fun1();
    }
    public static void fun1() throws ClassNotFoundException, SQLException {
       // Class.forName("com.mysql.jdbc.Driver");
        try{
            Driver driver=new com.mysql.jdbc.Driver();
            DriverManager.registerDriver(driver);

        }catch(SQLException e){
            e.printStackTrace();
            out.print("the driver ran failed");
        }
        out.print("hello\n");
        String url="jdbc:mysql://localhost:3306/mydb1";
        String username="root";
        String password="qertu1014";
         Connection con= DriverManager.getConnection(url,username,password);
         out.println(con);
    }
}
