unit FooBar;

interface

type

TFooBar = class
  private
    fFoo: integer;
  public
    Bar: boolean;

    constructor Create;
    destructor Destroy; override;

    procedure MultiplyByFive;
    function MultiplyByTen: integer;

    property Foo: integer read fFoo write fFoo;

end;

implementation

{ TFooBar }

constructor TFooBar.Create;
begin
  fFoo := 1;
  Bar := false;
end;

destructor TFooBar.Destroy;
begin
  //void
end;

procedure TFooBar.MultiplyByFive;
begin
  fFoo := fFoo * 5;
  Bar := true;
end;

function TFooBar.MultiplyByTen: integer;
begin
  result := fFoo * 10;
  Bar := false;
end;

end.
