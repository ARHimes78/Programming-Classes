
//Alan Himes
//ahimes1@cnm.edu
//Program 8 - Database Manipulation
//CIS2235
//File: MainP8.java, DbFrame.java, AddPanel.java, UpdatePanel.java, DeletePanel.java, Data.java, DbManager.java

package Data;

/**
 *
 * @author ahimes1
 */
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;

public class DbManager {
	//Add to beginning of MS Access DB URL
	private final String ACCESS_DB_URL_PREFIX =
		"jdbc:odbc:Driver={Microsoft Access Driver (*.mdb)};DBQ=";
	//Add to end of MS Access DB URL
	private final String ACCESS_DB_URL_SUFFIX = ";DriverID=22;READONLY=false;}";
	//File name of database
	private final String MY_DB_NAME = "Groceries.mdb";//changed

	private String fileName;
	private Connection myConnection;

	//constructor
	public DbManager() {
		try {
			myConnection = getAccessDbConnection(MY_DB_NAME);
			myConnection.setAutoCommit(true);
			DatabaseMetaData md = myConnection.getMetaData();
		} catch (SQLException ex) {
			Logger.getLogger
			            (DbManager.class.getName()).log(Level.SEVERE, null, ex);
			JOptionPane.showMessageDialog(null,
				"The database could not be located. Please select the database"
				+ " file you wish to connect to.",
				"Database Error", JOptionPane.ERROR_MESSAGE);
			JFileChooser chooser = new JFileChooser();
			chooser.showOpenDialog(chooser);
			fileName = chooser.getSelectedFile().toString();
			try {
				myConnection = getAccessDbConnection(fileName);
				myConnection.setAutoCommit(true);
				DatabaseMetaData md = myConnection.getMetaData();
			} catch (SQLException ex1) {
				Logger.getLogger
				       (DbManager.class.getName()).log(Level.SEVERE, null, ex1);
				JOptionPane.showMessageDialog(null,
					"The database could not be opened", "Fatal Error",
					JOptionPane.ERROR_MESSAGE);
			}
		}
	}

	//"destructor" method to release the database connection
	public void close() {
		try {
			myConnection.close();
		} catch (SQLException ex) {
			Logger.getLogger
			            (DbManager.class.getName()).log(Level.SEVERE, null, ex);
		}
	}

	//public methods to access the database
	public void insert(Data d) throws SQLException {//changed
		String sql;
		
                
                //build SQL statement
		sql = "INSERT INTO Groceries";//changed
		//sql += " (ItemName, YesNo, Number)";//changed
                sql += " (groceryitems, expensive, amount, comments)";
		sql += " VALUES (";
		sql += "'" + d.getGroceryItem() + "',";//changed
		sql += " " + d.getExpensive() + ",";
                sql += " " + d.getAmount() + ",";
                sql += " '" + d.getComments() + "');";
		
		insertRecord(sql);
	}
	public void update(Data d) throws SQLException {//changed
		String sql;
		//build SQL statement
		sql = "UPDATE Groceries SET";//changed
		sql += " groceryitems = '" + d.getGroceryItem() + "',";//changed
		sql += " expensive = " + d.getExpensive() + ",";//changed
		sql += " amount = " + d.getAmount() + ",";//changed
                sql += " comments = '" + d.getComments() + "'";
		sql += " WHERE id = " + d.getID() + ";";//changed
		updateRecord(sql);
	}
	public void delete(Data d) throws SQLException {//changed
		String sql;
		sql = "DELETE * FROM Groceries WHERE id = " + d.getID() + ";";//changed
		deleteRecord(sql);
	}
	public String[] getDataList() throws SQLException {//changed
		String strSql = "SELECT groceryitems FROM Groceries ORDER BY groceryitems;";//changed
		PreparedStatement ps = myConnection.prepareStatement(strSql,
			ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);

		ResultSet rs = ps.executeQuery();

		rs.last();
		int rowCount = rs.getRow();
		String[] items = new String[rowCount];

		try {
			rs.beforeFirst();
			int i = 0;
			while(rs.next()) {
				items[i] = rs.getString("groceryitems");
				i++;
			}
		} catch (Exception ex){
			JOptionPane.showMessageDialog(null,
				"getDataList: Unable to read item names: " + ex.getMessage());//
			System.out.println(ex.getStackTrace());
			System.out.println(ex.getLocalizedMessage());
		}

		return items;
	}
	public int[] getDataID() throws SQLException {//changed
		int[] id;
		String strSql = "SELECT id FROM Groceries ORDER BY groceryitems;";//changed
		PreparedStatement ps = myConnection.prepareStatement(strSql,
			ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);

		ResultSet rs = ps.executeQuery();

		rs.last();
		int rowCount = rs.getRow();
		id = new int[rowCount];

		try {
			rs.beforeFirst();
			int i = 0;
			while(rs.next()) {
				id[i] = rs.getInt("id");//changed
				i++;
			}
		} catch (Exception ex) {
			JOptionPane.showMessageDialog(null,
				"getDataNums: Unable to read numbers: " + ex.getMessage());//changed
			System.out.println(ex.getStackTrace());
			System.out.println(ex.getLocalizedMessage());
		}

		return id;
	}
	public Data getData(int num) throws SQLException {//changed
		String[] rec;
		String strSql = "SELECT * FROM Groceries WHERE id = " + num + ";";//changed
		Data data = null;//changed
		PreparedStatement ps = myConnection.prepareStatement(strSql,
			ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
		ResultSet rs = ps.executeQuery();
		ResultSetMetaData rsMeta = rs.getMetaData();
		int columns = rsMeta.getColumnCount();
		rec = new String[columns];
		try {
			rs.beforeFirst();
			while(rs.next()) {
				for (int i = 0; i < columns; i++) {
					rec[i] = rs.getString(i + 1);
				}
			}

			//use the data to build the Horse object
			data = new Data(//changed
				rec[0],
				rec[1],
				rec[2],
				rec[3],
				rec[4]
			);
		} catch (SQLException ex) {
			System.out.println(ex.getStackTrace());
			System.out.println(ex.getLocalizedMessage());
		}
		return data;//changed
	}

	//private method to establish database connection
	private Connection getAccessDbConnection(String fileName) throws SQLException {
                
		try {
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
		} catch (ClassNotFoundException ex) {
			System.err.println("JdbcOdbc Bridge Driver not Found");
			JOptionPane.showMessageDialog(null, ex.getMessage(), "Driver Error",
				JOptionPane.ERROR_MESSAGE);
			System.exit(0);
		}
                                
                String databaseURL = ACCESS_DB_URL_PREFIX + fileName + ACCESS_DB_URL_SUFFIX;
                
		return DriverManager.getConnection(databaseURL);
	}

	//private methods to access the database
	private void insertRecord(String strSql) throws SQLException {
		
            Statement st = myConnection.createStatement();
		try {
			st.execute(strSql);
                        
		} catch (SQLException ex) {
			System.err.println(ex.getStackTrace());
			System.err.println(ex.getMessage());
			System.err.println(ex.getLocalizedMessage());
		}
            st.close();
	}
	private void updateRecord(String strSql) throws SQLException {
		//use prepared statement to ensure that the result set is editable
		PreparedStatement ps = myConnection.prepareStatement(strSql,
			ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
		try {
			ps.execute();
		} catch (SQLException ex) {
			System.err.println(ex.getStackTrace());
			System.err.println(ex.getMessage());
			System.err.println(ex.getLocalizedMessage());
		}
	}
	private void deleteRecord(String strSql) throws SQLException {
		PreparedStatement ps = myConnection.prepareStatement(strSql,
			ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
		try {
			ps.execute();
		} catch (SQLException ex) {
			System.err.println(ex.getStackTrace());
			System.err.println(ex.getMessage());
			System.err.println(ex.getLocalizedMessage());
		}
	}
}


