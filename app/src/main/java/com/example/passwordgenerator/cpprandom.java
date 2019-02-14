package com.example.passwordgenerator;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class cpprandom extends AppCompatActivity {
    public native static String stringFrom(int ab);
    static {
        System.loadLibrary("native-lib");
    }
    EditText editText;
    String s;
    int o;
    private boolean isEmpty(EditText etText) {
        if (etText.getText().toString().trim().length() > 0)
            return false;

        return true;
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        final Intent intent=getIntent();
        setContentView(R.layout.random);
        editText= findViewById(R.id.editText);
        final Button button1 = findViewById(R.id.button);
        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(!isEmpty(editText)) {
                    o=Integer.parseInt(editText.getText().toString());
                    s=stringFrom(o);
                    Intent intent1=new Intent(cpprandom.this,final1.class);
                    intent1.putExtra("rand",s);
                    startActivity(intent1);
                }
                else {
                    Toast toast=Toast.makeText(getApplicationContext(),"Please enter a number",Toast.LENGTH_SHORT);
                    toast.show();
                }
            }
        });
    }

}
