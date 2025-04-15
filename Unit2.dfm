object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 761
  ClientWidth = 1222
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 185
    Width = 1222
    Height = 3
    Cursor = crVSplit
    Align = alTop
    ExplicitTop = 241
    ExplicitWidth = 501
  end
  object Splitter2: TSplitter
    Left = 794
    Top = 188
    Height = 573
    ExplicitLeft = 791
    ExplicitTop = 191
    ExplicitHeight = 443
  end
  object Splitter3: TSplitter
    Left = 385
    Top = 188
    Width = 409
    Height = 573
    ExplicitLeft = 383
    ExplicitTop = 191
    ExplicitHeight = 443
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1222
    Height = 185
    Align = alTop
    Caption = ' '
    Color = clMoneyGreen
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentBackground = False
    ParentFont = False
    TabOrder = 0
    ExplicitLeft = -1
    object Label1: TLabel
      Left = 19
      Top = 10
      Width = 48
      Height = 13
      Caption = 'Registry'
    end
    object Label2: TLabel
      Left = 852
      Top = 116
      Width = 43
      Height = 13
      Caption = #1053#1072#1095#1072#1083#1086
    end
    object COMListBox: TListBox
      Left = 19
      Top = 29
      Width = 326
      Height = 132
      ItemHeight = 13
      Items.Strings = (
        'COMListBox')
      TabOrder = 0
    end
    object CloseButton: TButton
      Left = 852
      Top = 29
      Width = 255
      Height = 68
      Caption = 'Close'
      TabOrder = 1
    end
    object RadioGroup_XAxes: TRadioGroup
      Left = 362
      Top = 29
      Width = 464
      Height = 57
      Caption = 'Axes '#1061' (pix)'
      Columns = 7
      ItemIndex = 5
      Items.Strings = (
        '1000'
        '2000'
        '3000'
        '4000'
        '5000'
        '6000'
        '10000')
      TabOrder = 2
    end
    object RG_MarkerStep: TRadioGroup
      Left = 360
      Top = 104
      Width = 466
      Height = 57
      Caption = 'Marker step (m)'
      Columns = 7
      ItemIndex = 5
      Items.Strings = (
        '1'
        '2'
        '5'
        '10'
        '12'
        '20'
        '50')
      TabOrder = 3
    end
    object CB_StartBox: TComboBox
      Left = 852
      Top = 135
      Width = 141
      Height = 26
      DropDownCount = 25
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ItemIndex = 0
      ParentFont = False
      TabOrder = 4
      Text = '0'
      Items.Strings = (
        '0'
        '10'
        '20'
        '50'
        '100'
        '150'
        '200'
        '250'
        '300'
        '350'
        '400'
        '450'
        '500'
        '550'
        '600'
        '650'
        '700'
        '750'
        '800'
        '850'
        '900'
        '950'
        '1000')
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 188
    Width = 385
    Height = 573
    Align = alLeft
    Caption = ' '
    TabOrder = 1
    ExplicitHeight = 437
    object GroupBox1: TGroupBox
      Left = 1
      Top = 1
      Width = 381
      Height = 435
      Align = alCustom
      Caption = 'KMD'
      Color = clMoneyGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentBackground = False
      ParentColor = False
      ParentFont = False
      TabOrder = 0
      object GroupBox3: TGroupBox
        Left = 3
        Top = 21
        Width = 370
        Height = 113
        Caption = 'USB'
        TabOrder = 0
        object CBox_KMDUSB: TComboBox
          Left = 15
          Top = 20
          Width = 130
          Height = 26
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
        end
        object RG_KMDUSB: TRadioGroup
          Left = 151
          Top = 13
          Width = 216
          Height = 84
          Caption = 'BaudRate'
          Columns = 3
          ItemIndex = 5
          Items.Strings = (
            '2400'
            '4800'
            '9600'
            '19200'
            '38400'
            '115200')
          TabOrder = 1
        end
        object KMDUSBButton: TButton
          Left = 38
          Top = 63
          Width = 105
          Height = 33
          Caption = 'Test connection'
          TabOrder = 2
        end
        object CheckBox_KMDUSB: TCheckBox
          Left = 15
          Top = 64
          Width = 15
          Height = 25
          Caption = ' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
        end
      end
      object GroupBox4: TGroupBox
        Left = 3
        Top = 140
        Width = 370
        Height = 113
        Caption = 'Bluetooth'
        TabOrder = 1
        object CBox_KMDBth: TComboBox
          Left = 15
          Top = 20
          Width = 130
          Height = 26
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
        end
        object RG_KMDBth: TRadioGroup
          Left = 151
          Top = 11
          Width = 216
          Height = 84
          Caption = 'BaudRate'
          Columns = 3
          ItemIndex = 5
          Items.Strings = (
            '2400'
            '4800'
            '9600'
            '19200'
            '38400'
            '115200')
          TabOrder = 1
        end
        object KMDBthButton: TButton
          Left = 38
          Top = 63
          Width = 105
          Height = 33
          Caption = 'Test connection'
          TabOrder = 2
        end
        object CheckBox_KMDBth: TCheckBox
          Left = 15
          Top = 72
          Width = 15
          Height = 25
          Caption = ' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
        end
      end
      object KMDMemo: TMemo
        Left = 15
        Top = 259
        Width = 355
        Height = 150
        Lines.Strings = (
          'KMDMemo')
        TabOrder = 2
      end
    end
  end
  object Panel3: TPanel
    Left = 391
    Top = 191
    Width = 400
    Height = 433
    Align = alCustom
    Anchors = [akLeft, akTop, akRight, akBottom]
    Caption = ' '
    TabOrder = 2
    ExplicitHeight = 437
    object GroupBox2: TGroupBox
      Left = 0
      Top = 0
      Width = 390
      Height = 432
      Align = alCustom
      Caption = 'GPS'
      Color = clMoneyGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentBackground = False
      ParentColor = False
      ParentFont = False
      TabOrder = 0
      object GPSMemo: TMemo
        Left = 16
        Top = 259
        Width = 361
        Height = 150
        Lines.Strings = (
          'GPSMemo')
        TabOrder = 0
      end
      object GroupBox5: TGroupBox
        Left = 5
        Top = 138
        Width = 372
        Height = 113
        Caption = 'Bluetooth'
        TabOrder = 1
        object CBox_GPSBth: TComboBox
          Left = 16
          Top = 20
          Width = 121
          Height = 26
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
        end
        object RG_GPSBth: TRadioGroup
          Left = 143
          Top = 13
          Width = 224
          Height = 84
          Caption = 'BaudRate'
          Columns = 3
          ItemIndex = 5
          Items.Strings = (
            '2400'
            '4800'
            '9600'
            '19200'
            '38400'
            '115200')
          TabOrder = 1
        end
        object GPSBthButton: TButton
          Left = 32
          Top = 63
          Width = 105
          Height = 33
          Caption = 'Test connection'
          TabOrder = 2
        end
        object CheckBox_GPSBth: TCheckBox
          Left = 8
          Top = 72
          Width = 15
          Height = 25
          Caption = ' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
        end
      end
      object GroupBox6: TGroupBox
        Left = 3
        Top = 16
        Width = 374
        Height = 113
        Caption = 'USB'
        TabOrder = 2
        object CBox_GPSUSB: TComboBox
          Left = 16
          Top = 23
          Width = 121
          Height = 26
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
        end
        object RG_GPSUSB: TRadioGroup
          Left = 143
          Top = 19
          Width = 224
          Height = 84
          Caption = 'BaudRate'
          Columns = 3
          ItemIndex = 5
          Items.Strings = (
            '2400'
            '4800'
            '9600'
            '19200'
            '38400'
            '115200')
          TabOrder = 1
        end
        object GPSUSBButton: TButton
          Left = 32
          Top = 63
          Width = 109
          Height = 33
          Caption = 'Test connection'
          TabOrder = 2
        end
        object CheckBox_GPSUSB: TCheckBox
          Left = 8
          Top = 64
          Width = 15
          Height = 25
          Caption = ' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
        end
      end
    end
  end
  object Panel4: TPanel
    Left = 797
    Top = 188
    Width = 425
    Height = 573
    Align = alClient
    Caption = 'Panel4'
    TabOrder = 3
    ExplicitWidth = 341
    ExplicitHeight = 437
    object GroupBox7: TGroupBox
      Left = 1
      Top = 1
      Width = 423
      Height = 571
      Align = alClient
      Caption = 'Fragment Search'
      Color = clMoneyGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentBackground = False
      ParentColor = False
      ParentFont = False
      TabOrder = 0
      ExplicitWidth = 339
      ExplicitHeight = 435
      object LabelLat: TLabel
        Left = 192
        Top = 23
        Width = 21
        Height = 13
        Caption = 'Lat:'
      end
      object LabelLng: TLabel
        Left = 192
        Top = 51
        Width = 23
        Height = 13
        Caption = 'Lng:'
      end
      object Chart1: TChart
        Left = 16
        Top = 96
        Width = 305
        Height = 329
        MarginBottom = 0
        MarginLeft = 0
        MarginRight = 5
        MarginTop = 0
        Title.Text.Strings = (
          '')
        BottomAxis.StartPosition = 2.000000000000000000
        BottomAxis.EndPosition = 98.000000000000000000
        View3D = False
        Color = clWhite
        TabOrder = 0
        ColorPaletteIndex = 13
        object Series1: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          ShowInLegend = False
          LinePen.Color = clRed
          LinePen.Width = 2
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series2: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = clBlue
          ShowInLegend = False
          LinePen.Color = clBlue
          LinePen.Width = 2
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
      object ButtonSelectFragment: TButton
        Left = 13
        Top = 23
        Width = 140
        Height = 33
        Caption = 'Select fragment'
        TabOrder = 1
      end
      object CB_FragmSearch: TCheckBox
        Left = 17
        Top = 73
        Width = 72
        Height = 17
        Caption = 'Active'
        TabOrder = 2
      end
    end
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'DAT'
    Filter = 'Data files (*.dat)|*.DAT'
    InitialDir = 'C:\VIZOR\DB\Fragments'
    Left = 1064
    Top = 128
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 3000
    Left = 792
  end
end
