import java.util.*;
import java.io.*;

class Dict {
    static Map<String, String[]> dictionary =
        new HashMap<String, String[]>();

    public int getDictSize() {
        int size = 8 * dictionary.size();

        for (Map.Entry<String, String[]> entry : dictionary.entrySet()) {
            String key = entry.getKey();
            String[] value = entry.getValue();

            size += 8 * (int) (((key.length() * 2) + 45) / 8);

            for (String s : value) {
                size += 8 * (int) (((s.length() * 2) + 45) / 8);
            }
        }

        return size;
    }

    public String convertToLeet(String str) {
        str = str.toUpperCase();
        Random rand = new Random();
        int whichOne;

        for (Map.Entry<String, String[]> entry : dictionary.entrySet()) {
            String key = entry.getKey();
            String[] value = entry.getValue();
            whichOne = rand.nextInt(value.length);

            str = str.replace(key, value[whichOne]);
        }

        return str;
    }

    public static void main(String[] args) {
        dictionary.put("A", new String[] {"4", "/-\\"});
        dictionary.put("B", new String[] {"8", "|3", "ss"});
        dictionary.put("C", new String[] {"<", "("});
        dictionary.put("D", new String[] {"|)", "|]", "|>"});
        dictionary.put("E", new String[] {"3"});
        dictionary.put("F", new String[] {"|="});
        dictionary.put("G", new String[] {"[", "6"});
        dictionary.put("H", new String[] {"|-|"});
        dictionary.put("I", new String[] {"1", "|"});
        dictionary.put("J", new String[] {"_|"});
        dictionary.put("K", new String[] {"|<", "|{"});
        dictionary.put("L", new String[] {"|_"});
        dictionary.put("M", new String[] {"44", "|\\/|"});
        dictionary.put("N", new String[] {"|\\|"});
        dictionary.put("O", new String[] {"0"});
        dictionary.put("P", new String[] {"|o"});
        dictionary.put("Q", new String[] {"O_", "kw"});
        dictionary.put("R", new String[] {"|2", "12"});
        dictionary.put("S", new String[] {"5", "$"});
        dictionary.put("T", new String[] {"7", "+"});
        dictionary.put("U", new String[] {"|_|"});
        dictionary.put("V", new String[] {"\\/"});
        dictionary.put("W", new String[] {"\\/\\/", "?"});
        dictionary.put("X", new String[] {"?", ")(", "}{"});
        dictionary.put("Y", new String[] {"?", "JPY"});
        dictionary.put("Z", new String[] {"2", "5", "7_"});

        Dict d = new Dict();

        System.out.println("Size of the HashMap: " + d.getDictSize() + " bytes");

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);

        try {
            String l = null;
            while (!(l = br.readLine()).trim().equals("")) {
                System.out.println(d.convertToLeet(l));
                System.out.println();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}