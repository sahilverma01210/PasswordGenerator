package com.example.passwordgenerator;

import android.content.ClipData;
import android.content.ClipboardManager;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class final3 extends AppCompatActivity {
    Button button;
    String[] s=new String[2];
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        final Intent intent=getIntent();
        super.onCreate(savedInstanceState);
        setContentView(R.layout.final3);
        button=(Button)findViewById(R.id.button8);
        TextView textView=(TextView)findViewById(R.id.textView11);
        TextView textView1=(TextView)findViewById(R.id.textView5);
        s=intent.getStringArrayExtra("ft");
        textView.setText(s[0]);
        textView1.setText("Hint:- "+s[1]);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ClipboardManager clipboard = (ClipboardManager) getSystemService(Context.CLIPBOARD_SERVICE);
                ClipData clip = ClipData.newPlainText("text2",s[0]);
                clipboard.setPrimaryClip(clip);
                Toast toast=Toast.makeText(getApplicationContext(),"Copied to clipboard",Toast.LENGTH_SHORT);
                toast.show();
            }
        });
    }
}
