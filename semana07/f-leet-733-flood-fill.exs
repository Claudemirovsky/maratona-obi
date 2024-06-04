defmodule Solution do
  defp get_or_nil(image, x, y) do
    cond do
      x < 0 or y < 0 or x >= tuple_size(image) or y >= tuple_size(elem(image, 0)) -> nil
      true -> image |> elem(x) |> elem(y)
    end
  end

  @spec flood_fill(image :: [[integer]], sr :: integer, sc :: integer, color :: integer) :: [[integer]]
  def flood_fill(image, sr, sc, color) do
    image
      |> Enum.map(&List.to_tuple/1)
      |> List.to_tuple()
      |> (&fill(&1, sr, sc, color, get_or_nil(&1, sr, sc))).()
      |> Tuple.to_list()
      |> Enum.map(&Tuple.to_list/1)
  end

  defp fill(image, _x, _y, color, oldcolor) when color == oldcolor, do: image

  @movs [{0, 1}, {0, -1}, {1, 0}, {-1, 0}]
  defp fill(image, x, y, color, oldcolor) do 
    if get_or_nil(image, x, y) == oldcolor do
        image = image
        |> elem(x)
        |> put_elem(y, color)
        |> (&put_elem(image, x, &1)).()

        @movs
          |> Enum.reduce(image, fn {ax, ay}, img -> fill(img, x + ax, y + ay, color, oldcolor) end)
    else
        image
    end
  end
end

Solution.flood_fill([[1,1,1], [1,1,0], [1,0,1]], 1, 1, 2)
  |> IO.inspect(label: "final")
