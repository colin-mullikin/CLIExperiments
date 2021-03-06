library DelphiDLL;

{ Important note about DLL memory management: ShareMem must be the
  first unit in your library's USES clause AND your project's (select
  Project-View Source) USES clause if your DLL exports any procedures or
  functions that pass strings as parameters or function results. This
  applies to all strings passed to and from your DLL--even those that
  are nested in records and classes. ShareMem is the interface unit to
  the BORLNDMM.DLL shared memory manager, which must be deployed along
  with your DLL. To avoid using BORLNDMM.DLL, pass string information
  using PChar or ShortString parameters. }

uses
  System.SysUtils,
  System.Classes,
  FooBar in 'FooBar.pas';

{$R *.res}

function CreateFooBar: Pointer; stdcall;
begin
  result := TFooBar.Create;
end;

procedure DestroyFooBar(aFooBar: Pointer); stdcall;
begin
  TFooBar(aFooBar).Free;
end;

procedure MultiplyByFive(aFooBar: Pointer); stdcall;
begin
  TFooBar(aFooBar).MultiplyByFive;
end;

function MultiplyByTen(aFooBar: Pointer): integer; stdcall;
begin
  result := TFooBar(aFooBar).MultiplyByTen;
end;

function GetFoo(aFooBar: Pointer): integer; stdcall;
begin
  result := TFooBar(aFooBar).Foo;
end;

function GetBar(aFooBar: Pointer): boolean; stdcall;
begin
  result := TFooBar(aFooBar).Bar;
end;

exports CreateFooBar,
        DestroyFooBar,
        MultiplyByFive,
        MultiplyByTen,
        GetFoo,
        GetBar;


begin
end.
