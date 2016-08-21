import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class Main {

	public static void main(String[] argc) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String linea;
		while( (linea = bf.readLine()) != null )
		{
			List< BigInteger > numbers = new ArrayList<>();
			for(String aux : linea.split("\\s+"))
			{
				if( !aux.equals("-999999") )
				{
					numbers.add( new BigInteger( aux ) );
				}
			}
			BigInteger maximo = new BigInteger("-999999");
			for( int i = 0 ; i < numbers.size() ; i++ )
			{
				BigInteger acum = BigInteger.ONE;
				for(int j = i ; j < numbers.size() ; j++)
				{
					acum = acum.multiply( numbers.get( j ) );
					maximo = acum.max( maximo );
				}
			}
			System.out.println(maximo);
		}
	}
}
