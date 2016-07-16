package com.example.administrator.ndkstudy;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("JniTest");
    }
    TextView txtView;
    EditText editText;
    String str;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
         txtView = (TextView)findViewById(R.id.txt);
        editText=(EditText)findViewById(R.id.input);
        str=null;

        Button button=( Button)findViewById(R.id.sure);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                str=editText.getText().toString();
                  if(str!=null)
                txtView.setText(getStringFromNative(str));
            }
        });


    }


    public native String getStringFromNative(String str);

}
