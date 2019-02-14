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

public class final1 extends AppCompatActivity {
    Button button;
    String s;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        final Intent intent=getIntent();
        super.onCreate(savedInstanceState);
        setContentView(R.layout.final1);
        button=(Button)findViewById(R.id.button6);
        TextView textView=(TextView)findViewById(R.id.textView12);
        s=intent.getExtras().getString("rand");
        textView.setText(s);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ClipboardManager clipboard = (ClipboardManager) getSystemService(Context.CLIPBOARD_SERVICE);
                ClipData clip = ClipData.newPlainText("text",s);
                clipboard.setPrimaryClip(clip);
                Toast toast=Toast.makeText(getApplicationContext(),"Copied to clipboard",Toast.LENGTH_SHORT);
                toast.show();
            }
        });
    }
}
