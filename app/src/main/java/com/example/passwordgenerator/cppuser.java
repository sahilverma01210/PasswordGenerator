package com.example.passwordgenerator;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class cppuser extends AppCompatActivity {
    public native static String[] stringFromUser(String[] str);
    static {
        System.loadLibrary("native-lib");
    }
    private boolean isEmpty(EditText etText) {
        if (etText.getText().toString().trim().length() > 0)
            return false;

        return true;
    }
    boolean check(char[] chars){
        int c=0;
        for(int i=0;i<chars.length;i++){
            if(chars[i]==' '){
               c++;
            }
        }
        if(c!=0){
            return true;
        }
        else {
            return false;
        }
    }
    EditText name,fname,dob,place;
    String[] s=new String[2];
    String[] u_info=new String[4];
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        final Intent intent=getIntent();
        setContentView(R.layout.user_info);
        final Button button1 = findViewById(R.id.button);
        name=(EditText)findViewById(R.id.editText);
        dob=(EditText)findViewById(R.id.editText3);
        fname=(EditText)findViewById(R.id.editText4);
        place=(EditText)findViewById(R.id.editText5);
        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!isEmpty(name) && !isEmpty(dob) && !isEmpty(fname) && !isEmpty(place)){
                    u_info[0] = name.getText().toString();
                u_info[1] = dob.getText().toString();
                u_info[2] = fname.getText().toString();
                char[] a = dob.getText().toString().toCharArray();
                char[] b = fname.getText().toString().toCharArray();
                char[] c = name.getText().toString().toCharArray();
                char[] d = place.getText().toString().toCharArray();
                u_info[3] = place.getText().toString();
                if (a[2] == '/' && a[5] == '/' && a.length == 10) {
                    if (!check(b) && !check(c) && !check(d)) {
                        s = stringFromUser(u_info);
                        Intent intent1 = new Intent(cppuser.this, final2.class);
                        intent1.putExtra("usr", s);
                        startActivity(intent1);
                    } else {
                        Toast toast = Toast.makeText(getApplicationContext(), "No spaces allowed", Toast.LENGTH_SHORT);
                        toast.show();
                    }
                } else {
                    Toast toast = Toast.makeText(getApplicationContext(), "Please enter dob in dd/mm/yyyy format ", Toast.LENGTH_SHORT);
                    toast.show();
                }
            }
            else{
                    Toast toast=Toast.makeText(getApplicationContext(),"Please enter all credentials",Toast.LENGTH_SHORT);
                    toast.show();
                }
            }
        });
    }
}
