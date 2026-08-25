import java.net.InetAddress;
import java.net.UnknownHostException;

public class NetClass {
    private static InetAddress addr;


    public static void main(String... args) throws UnknownHostException {
        addr = InetAddress.getByName("localhost");
        String hostAddr = addr.getHostAddress();
        String hostname = addr.getHostName();
        System.out.println("HOST ADDRESS IS " + hostAddr);
        System.out.println("HOSTNAME IS " + hostname);
    }
}