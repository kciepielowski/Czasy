object Form1: TForm1
  Left = 441
  Top = 331
  Width = 574
  Height = 263
  Caption = 'Przyk'#322'adowe zdania w ka'#380'dym czasie j'#281'zyka angielskiego.'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object result: TLabel
    Left = 8
    Top = 184
    Width = 218
    Height = 16
    Caption = 'Tu si'#281' pojawi przekszta'#322'cone zdanie.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 8
    Top = 112
    Width = 542
    Height = 13
    Caption = 
      'Zdanie w "Present Simple" z "prostym" podmiotem (i/you/he/she/it' +
      '/we/they/those)  bez czasownik'#243'w modalnych:'
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 81
    Height = 73
    TabOrder = 0
    object Past: TRadioButton
      Left = 8
      Top = 17
      Width = 65
      Height = 17
      Caption = 'Past'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = PastClick
    end
    object Present: TRadioButton
      Left = 8
      Top = 33
      Width = 65
      Height = 17
      Caption = 'Present'
      TabOrder = 1
      OnClick = PresentClick
    end
    object Future: TRadioButton
      Left = 8
      Top = 49
      Width = 57
      Height = 17
      Caption = 'Future'
      TabOrder = 2
      OnClick = FutureClick
    end
  end
  object GroupBox2: TGroupBox
    Left = 112
    Top = 8
    Width = 137
    Height = 97
    TabOrder = 1
    object Simple: TRadioButton
      Left = 9
      Top = 9
      Width = 116
      Height = 17
      Caption = 'Simple'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = SimpleClick
    end
    object Continuous: TRadioButton
      Left = 9
      Top = 25
      Width = 116
      Height = 17
      Caption = 'Continuous'
      TabOrder = 1
      OnClick = ContinuousClick
    end
    object Perfect: TRadioButton
      Left = 9
      Top = 41
      Width = 116
      Height = 17
      Caption = 'Perfect '
      TabOrder = 2
      OnClick = PerfectClick
    end
    object PerfectC: TRadioButton
      Left = 9
      Top = 58
      Width = 114
      Height = 17
      Caption = 'Perfect Continuous'
      TabOrder = 3
      OnClick = PerfectCClick
    end
    object PerfectP: TRadioButton
      Left = 9
      Top = 75
      Width = 113
      Height = 17
      Caption = 'Perfect In The Past'
      Enabled = False
      TabOrder = 4
      OnClick = PerfectPClick
    end
    object InThePast: TRadioButton
      Left = 9
      Top = 58
      Width = 113
      Height = 17
      Caption = 'In The Past'
      Enabled = False
      TabOrder = 5
      Visible = False
      OnClick = InThePastClick
    end
  end
  object Generuj: TButton
    Left = 288
    Top = 16
    Width = 233
    Height = 73
    Caption = 'Generuj'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = GenerujClick
  end
  object zdanie: TEdit
    Left = 8
    Top = 136
    Width = 553
    Height = 21
    TabOrder = 3
  end
end
