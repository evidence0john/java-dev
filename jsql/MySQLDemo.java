import java.sql.*;

public class MySQLDemo{
 
    static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";  
    static final String DB_URL = "jdbc:mysql://localhost:3306/jtrain";
    static final String USER = "root";
    static final String PASS = "2048";

    public static void main(String[] args) {
        Connection conn = null;
        Statement State = null;
        try{
            Class.forName("com.mysql.jdbc.Driver");
            //Connection
            conn = DriverManager.getConnection(DB_URL,USER,PASS);
            if(conn == null){
                System.out.println("Cannot establish connection");
            }
            //createStatement
            State = conn.createStatement();
            if(conn == null){
                System.out.println("Error while createStatement");
            }
            //query
            String sql;
            sql = "SELECT * FROM people";
            ResultSet query = State.executeQuery(sql);
        
            while(query.next()){
                int id  = query.getInt("id");
                String name = query.getString("name");
                String sex = query.getString("sex");
                String age = query.getString("age");
                String country = query.getString("country");
                
                //System.out.println("TEST" + query.getString());
                
                System.out.print("ID: " + id);
                System.out.print(", name: " + name);
                System.out.print(", sex: " + sex);
                System.out.print(", age: " + age);
                System.out.print(", from: " + country);
                System.out.print("\n");
            }
            query.close();
            State.close();
            conn.close();
        }catch(Exception e){
            e.printStackTrace();
        }finally{
            try{
                if(State!=null) State.close();
                if(conn!=null) conn.close();
            }catch(Exception e){
                e.printStackTrace();
            }
        }
        System.out.println("Finished");
    }
}
